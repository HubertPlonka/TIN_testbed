#pragma once

#include "TestCase.hpp"

#include <unordered_map>
#include <vector>
#include <string>

namespace tb 
{

class TCManager
{
public:
	void NewTestCase(
		std::string& tcName,
		tc_callback& tcFunc);

	// This is invoked from MainWindow after pressing "Test!"
	void RunTestCase(const std::string& tcName);
	void RunAllTestCases();
	/*
	* ABANDONED 
	*/
	// void ParseTxt();

private:
	// The optimalest mapa
	static std::unordered_map<std::string, TestCase> listOfTCs;
};

} // namespace tb
