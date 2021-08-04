#pragma once

#include "TestCase.hpp"

#include <string>

namespace tb
{

class SerialCom
{
public:
	static void RefreshAvailableCOMPorts();
	static void ProgramAVR(const std::string& hexFile);
	static void ProgramAVR(TestCase& tc);
};

}
