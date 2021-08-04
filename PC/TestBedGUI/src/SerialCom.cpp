#include "SerialCom.hpp"

namespace tb
{



void SerialCom::RefreshAvailableCOMPorts()
{
	return;
}

void SerialCom::ProgramAVR(const std::string& hexFile)
{
}

void SerialCom::ProgramAVR(TestCase& tc)
{
	ProgramAVR(tc.nameOfHex4AVR);
}

}