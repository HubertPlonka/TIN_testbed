#pragma once

#include "TestCase.hpp"

#include <unordered_map>
#include <vector>
#include <string>

namespace tb 
{
using TCMap = std::unordered_map<std::string, TestCase>;

class TCManager
{
public:
	static void NewTestCase(
		std::string& tcName,
		tc_callback& tcFunc);

	// This is invoked from MainWindow after pressing "Test!"
	static void RunTestCase(const std::string& tcName);
	static void RunAllTestCases();
	static const TCMap& GetAvailableTests();
	/*
	* ABANDONED 
	*/
	// void ParseTxt();

private:
	// The optimalest mapa
	static TCMap listOfTCs;
};

} // namespace tb
