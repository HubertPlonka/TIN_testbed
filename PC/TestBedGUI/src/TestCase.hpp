#pragma once

#include <functional>
#include <string>

namespace tb
{
using tc_callback = std::function<void()>;

struct TestCase
{
	TestCase(
		std::string tcName,
		tc_callback tc) :
		name(tcName), Run(tc)
	{
	}
	TestCase() = default;


	std::string name;
	tc_callback	Run;
	std::string nameOfHex4AVR;
};

} // namespace tb
