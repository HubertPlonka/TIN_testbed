#pragma once

#include <functional>
#include <string>

namespace tb
{
using tc_callback = std::function<void()>;

struct TestCase
{
	TestCase(
		std::string& tcName,
		tc_callback tc,
		std::string hex4Avr) :
		name(tcName), Run(tc), nameOfHex4AVR(hex4Avr)
	{
	}

	std::string name;
	tc_callback	Run;
	std::string nameOfHex4AVR;
};

} // namespace tb
