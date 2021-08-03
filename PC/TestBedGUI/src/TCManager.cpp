#include "TCManager.hpp"

#include "GUIManager.hpp"

namespace tb
{

void TCManager::NewTestCase(std::string& tcName, tc_callback& tcFunc, std::string& tcNameOfAVRhex)
{
	listOfTCs[tcName] = TestCase(tcName, tcFunc, tcNameOfAVRhex);
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

void TCManager::TestConsoleOut()
{
	GUIManager inst{};

	unsigned szofGm = sizeof(GUIManager);
	std::string sizeString = std::to_string(szofGm);
	std::string mes = "Rozmiar GUI managera ->";

	inst.PrintConsoleInfo(mes + sizeString);
}

} // namespace tb
