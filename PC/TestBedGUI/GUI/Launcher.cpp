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

	GUIManager* man = new GUIManager();
	man->PrintConsoleInfo("Konsola dzia³a");
	man->PrintConsoleDebug("Debug dzia³a");
	man->PrintConsoleError("Error dzia³a");
	man->PrintTestState("Test state dziala", TestResult::PASS);
	delete man;

	return true;
}

} // namespace tb

