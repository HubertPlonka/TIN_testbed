#pragma once

#include <wx/wx.h>

namespace tb
{

enum WidgetID : int
{
	unused = 1000,
	ID_BEGIN_TEST_BUTTON,
	ID_TC_LIST,
	ID_TERMINAL,
	ID_COM_PORT_SEL,
	ID_REFRESH_COM_MENU,
	ID_REFRESH_TC_MENU
};

class MainWindow : public wxFrame
{
public:
	MainWindow();

private:
	wxButton* beginTestB = nullptr;

	void OnQuit(wxCommandEvent& evt);

};

} // namespace tb
