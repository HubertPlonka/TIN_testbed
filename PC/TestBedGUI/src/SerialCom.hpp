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
	static void ProgramAVR(const std::string& hexFile);	// Maybe obsolete ?
	static void ProgramAVR(TestCase& tc);				// Maybe obsolete ?
	
	SerialCom(const std::string& portName);
	~SerialCom();
	void PingCOM();
	void ReadCOM(std::string& messageBuff);
	void Write2COM(const std::string& message);

private:
	std::string COMPort;
};

}
