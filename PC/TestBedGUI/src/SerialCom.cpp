#include "SerialCom.hpp"

#include "../ext/enumser/stdafx.h"
#include "../ext/enumser/enumser.h"

#include "../ext/SerialComHelper/SerialCommHelper.h"

#include "GUIManager.hpp"

#include <cstdio>
#include <memory>

namespace tb
{
    static constexpr char PING_REQ[]    = "PING";
    static constexpr char PING_RESP[]   = "PONG";

    static std::unique_ptr<CSerialCommHelper> serialComInstance;

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
/*  // Not in this relase :)
void SerialCom::ProgramAVR(const std::string& hexFile)
{
}

void SerialCom::ProgramAVR(TestCase& tc)
{
	ProgramAVR(tc.nameOfHex4AVR);
}
*/
SerialCom::SerialCom(const std::string& portName) :
    COMPort(portName)
{
    serialComInstance = std::make_unique<CSerialCommHelper>(CSerialCommHelper());
    serialComInstance->Init(portName);
    serialComInstance->Start();
}

SerialCom::~SerialCom()
{
    serialComInstance->Stop();
    serialComInstance->UnInit();
    serialComInstance.release();
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
    if (!serialComInstance)
    {
        GUIManager::PrintConsoleError("Port communication uninitialized");
        return;
    }

    serialComInstance->ReadAvailable(messageBuff);
}

void SerialCom::Write2COM(const std::string& message)
{
    if (!serialComInstance)
    {
        GUIManager::PrintConsoleError("Port communication uninitialized");
        return;
    }

    serialComInstance->Write(message.c_str(), message.size());
}

}