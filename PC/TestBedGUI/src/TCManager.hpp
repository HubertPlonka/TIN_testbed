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
		tc_callback& tcFunc,
		std::string& tcNameOfAVRhex);

	void RunTestCase(const std::string& tcName);
	void RunAllTestCases();

	void TestConsoleOut();

	/*
	* Funkcja do czytania txt ¿eby zrobiæ tc 
	* (mo¿e byæ w innej klasie czy cuœ)
	*/

private:
	// The optimalest mapa
	std::unordered_map<std::string, TestCase> listOfTCs;
};

} // namespace tb
