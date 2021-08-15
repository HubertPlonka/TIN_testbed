/*	ABANDONED
	@How to write test case in txt:
	1) Whitespace and lines starting with # are ignored
	2) First line MUST BE test name without any whitespace 
		and non ASCII characters
	3) There are 2 commands:
		- "R(cmp, port)"
		- "W(val, port)"
		They are of course read and write commands which are executed 
		by STM uC on AVR pins 
		R() -> Read pins corresponding to AVR PORTX register and compare 
				read values to cmp	(port arg may be any of A, B, C, D... (any of available AVR ports))
				cmp must be hex constant (i.e. 0x48), test case will compare it with & bitwise function
				and print on builtin terminal result of comparison
		W() -> Tell AVR (through STM) to write val (hex value) to corresponding PORTX register
				this command will print on builtin terminal what has been written to particular port
*/

#include "TCParser.hpp"

#include <fstream>

namespace tb
{

void TCParser::CreateTCFromTxt(
	const std::string& path,
	TestCase& out_TC)
{

}
}
