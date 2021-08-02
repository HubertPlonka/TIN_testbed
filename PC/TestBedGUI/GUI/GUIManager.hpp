#pragma once

#include <string>
#include <functional>

namespace tb
{

/*
	Since it is quite inconvenient to separate GUI style from functional
	code in wxWidgets, this class is supposed to be kinda facade over GUI
	If you want to modify sth directly in GUI, use this class istead of including MainWindow
	or wx/wx.h directly
	If there is sth that you want to use and this class does not provide it, plz implement
	this in new method
*/

enum class LogLevel : unsigned
{
	TC_RESULT_ONLY,		/* Print only wheather test passed or failed */
	INFO,				/* Print [INFO] messages, general info, may be in relase version */
	ERROR,				/* Print [ERROR] messages, for more precise info about test fail reason */
	DEBUG				/* Print [DEBUG] messages, for debugging, turn off for relase */
};

enum class TestResult : unsigned
{
	PASS,
	FAIL
};

class GUIManager
{
public:
	//////////////////////////////////////////////////////
	// Print to GUI "console" window
	//////////////////////////////////////////////////////
	void SetLoggingLevel(const LogLevel llvl);
	void PrintConsoleInfo(const std::string& message);
	void PrintConsoleError(const std::string& message);
	void PrintConsoleDebug(const std::string& message);
	void PrintTestState(
		const std::string& message, 
		const TestResult result);
	//////////////////////////////////////////////////////

	void AddCOMPort(std::string& name, unsigned ID);
	std::string GetSelectedCOM();

	void AddTestCase(
			const std::string& name,		/* Name displayed on tc list */
			std::function<void()>& tcFunc,	/* Function to call when Test! button is pressed */
			const std::string& hex2PrgAVR);	/* Name of .hex file (path is fixed to ..\AVRtc\) */
	// TODO: add menu option for this xD
	void SaveTestLogToFile(const std::string& fileName);
	void ClearTestCasesTable();
};

} //namespace tb
