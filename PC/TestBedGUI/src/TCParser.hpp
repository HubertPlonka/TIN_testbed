/*
	ABANDONED
	Jak ktoœ ma za du¿o czasu w ¿yciu to zapraszam ale ja nie zamierzam
	robiæ swojego gcc :)
*/
#pragma once

#include <string>
#include <vector>
#include <functional>

#include "TestCase.hpp"

namespace tb
{

class TCParser
{
public:
	static void CreateTCFromTxt(
		const std::string& path,
		TestCase& out_TC);

private:
	TCParser() = delete;
	TCParser(TCParser&) = delete;
	TCParser(TCParser&&) = delete;
};

} // namespace tb
