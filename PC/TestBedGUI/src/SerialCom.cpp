#include "SerialCom.hpp"

#include "../ext/enumser/stdafx.h"
#include "../ext/enumser/enumser.h"

#include "../ext/SerialComHelper/SerialCommHelper.h"

#include "GUIManager.hpp"

#include <cstdio>
#include <memory>
#include <unordered_map>

namespace tb
{
    static constexpr char PING_REQ[]    = "PING";
    static constexpr char PING_RESP[]   = "PONG";

    static std::unordered_map<std::string, std::unique_ptr<CSerialCommHelper>> serialComInstanceList;

static void SygnalizeError(const std::string& errMessage, HRESULT errCode)
{
    GUIManager::PrintConsoleError(errMessage + " Error code: " + std::to_string(errCode));
}

void SerialCom::RefreshAvailableCOMPorts(std::vector<std::string>& listOfCOMs)
{
    CEnumerateSerial::CPortsArray ports;

    if (CEnumerateSerial::UsingCreateFile(ports))
    {
        for (auto item : ports)
        {
            listOfCOMs.push_back("COM" + std::to_string(item));
        }
    }
    else
    {
        SygnalizeError("CEnumerateSerial::UsingCreateFile failed", GetLastError());
    }
}

SerialCom::SerialCom(const std::string& portName) :
    COMPort(portName)
{
    serialComInstanceList[COMPort] = std::make_unique<CSerialCommHelper>(CSerialCommHelper());
    auto& COMInst = serialComInstanceList[COMPort];
    COMInst->Init(portName);
    COMInst->Start();
}

SerialCom::~SerialCom()
{
    auto& COMInst = serialComInstanceList[COMPort];
    COMInst->Stop();
    COMInst->UnInit();
    COMInst.release();
}

void SerialCom::PingCOM()
{
    std::string buff;

    Write2COM(PING_REQ);
    ReadCOM(buff);

    if (buff == PING_RESP)
    {
        GUIManager::PrintConsoleInfo("Found valid device on " + COMPort);
        return;
    }

    if (buff.empty())
    {
        GUIManager::PrintConsoleError("No device found on " + COMPort);
        return;
    }
    else
    {
        GUIManager::PrintConsoleError("Invalid device on " + COMPort);
        return;
    }
}

void SerialCom::ReadCOM(std::string& messageBuff)
{
    auto& COMInst = serialComInstanceList[COMPort];
    if (!COMInst)
    {
        GUIManager::PrintConsoleError("Port communication uninitialized");
        return;
    }

    COMInst->ReadAvailable(messageBuff);
}

void SerialCom::Write2COM(const std::string& message)
{
    auto& COMInst = serialComInstanceList[COMPort];
    if (!COMInst)
    {
        GUIManager::PrintConsoleError("Port communication uninitialized");
        return;
    }

    COMInst->Write(message.c_str(), message.size());
}

}