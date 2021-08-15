#include "TCManager.hpp"

#include "GUIManager.hpp"

namespace tb
{

void TCManager::NewTestCase(std::string& tcName, tc_callback& tcFunc)
{
	listOfTCs[tcName] = TestCase(tcName, tcFunc);
}

void TCManager::RunTestCase(const std::string& tcName)
{
	if (tcName == "RUN ALL")
		RunAllTestCases();

	auto tc = listOfTCs.find(tcName);
	if (tc == listOfTCs.end())
	{
		GUIManager::PrintConsoleError("Test case " + tcName + " does not exist");
		return;
	}
	listOfTCs[tcName].Run();
}

void TCManager::RunAllTestCases()
{
	if (listOfTCs.empty())
	{
		GUIManager::PrintConsoleError("List of available tests is empty");
		return;
	}

	// Not guaranteed to be run in any order,
	// but it's not realy necessary 
	for (auto& tc : listOfTCs)
	{
		tc.second.Run();
	}
}

const TCMap& TCManager::GetAvailableTests()
{
	return listOfTCs;
}

} // namespace tb
