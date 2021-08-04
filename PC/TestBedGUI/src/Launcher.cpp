#include "wx/wx.h"
#include "Launcher.hpp"
#include "GUIManager.hpp"

namespace tb
{

wxIMPLEMENT_APP(Launcher);

bool Launcher::OnInit()
{
	mainFrame = new MainWindow();
	mainFrame->Show();

	GUIManager::PrintConsoleInfo("Konsola dzia³a");
	GUIManager::PrintConsoleDebug("Debug dzia³a");
	GUIManager::PrintConsoleError("Error dzia³a");
	GUIManager::PrintTestState("Test state dziala", TestResult::PASS);

	GUIManager::AddCOMPort("COM42");

	return true;
}

} // namespace tb

