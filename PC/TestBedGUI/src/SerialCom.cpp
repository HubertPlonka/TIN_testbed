#include "SerialCom.hpp"

#include "../ext/enumser/stdafx.h"
#include "../ext/enumser/enumser.h"

#include "GUIManager.hpp"

#include <cstdio>

namespace tb
{

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

void SerialCom::ProgramAVR(const std::string& hexFile)
{
}

void SerialCom::ProgramAVR(TestCase& tc)
{
	ProgramAVR(tc.nameOfHex4AVR);
}

}