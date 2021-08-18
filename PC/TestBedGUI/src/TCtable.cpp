/*
	Here should be defined all test cases as a separate functions 

	@HOW TO CREATE TEST CASE
	1) Write test function (below apropriate comment)
		-Function must return void and have 0 parameters (type void())
	2) Add name and TestCase object to static map on 
		the bottom of this file
	
	TODO: Maybe one day we should compile it as .dll?
*/
#include "TCManager.hpp"
#include "GUIManager.hpp"
#include "SerialCom.hpp"


namespace tb
{
// KOMENDY WYSY£ANE PRZEZ UART
// 0x01 - READ BYTES
// 0x02 - WRITE PINS


///////////////////////////////////////////////////////////////////////////
// Test case functions 
///////////////////////////////////////////////////////////////////////////

void ExampleTest()
{
	GUIManager::PrintTestState("Przyk³adowy test", TestResult::PASS);
}

void TestSerialCommunication()
{
	SerialCom AVR_COM(GUIManager::GetSelectedCOM(ConnectedDevice::AVR));

}

///////////////////////////////////////////////////////////////////////////
// Table of all test cases used by TCManager 
///////////////////////////////////////////////////////////////////////////

TCMap TCManager::listOfTCs{
	{"ExampleTest", TestCase("ExampleTest", ExampleTest)},
	{"TestSerialCommunication", TestCase("TestSerialCommunication", TestSerialCommunication)}
};

} // namespace tb
