#include "wx/wx.h"
#include "Launcher.hpp"

namespace tb
{

wxIMPLEMENT_APP(Launcher);

bool Launcher::OnInit()
{
	mainFrame = new MainWindow();
	mainFrame->Show();

	return true;
}

} // namespace tb

