#pragma once

#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

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
	ID_REFRESH_TC_MENU,
	ID_PROGRAM_AVR_MENU
};

class MainWindow : public wxFrame
{
public:
	MainWindow();

private:
	wxButton* beginTestB = nullptr;
	wxRichTextCtrl* terminalWindow = nullptr;
	wxChoice* COMsel = nullptr;
	wxListBox* tcList = nullptr;
	wxButton* selectButton = nullptr;

	void OnQuit(wxCommandEvent& evt);

};

} // namespace tb
