#pragma once

#include "TestCase.hpp"

#include <string>
#include <vector>

namespace tb
{

class SerialCom
{
public:
	static void RefreshAvailableCOMPorts(std::vector<std::string>& listOfCOMs);
	static void ProgramAVR(const std::string& hexFile);
	static void ProgramAVR(TestCase& tc);
	//static void 
};

}
