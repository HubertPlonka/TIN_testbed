#include "MainWindow.hpp"
#include <wx/richtext/richtextctrl.h>


namespace tb
{
	constexpr char _WINDOW_TITLE[] = "AVR TestBed v0.0.1"; 

MainWindow::MainWindow() : wxFrame(
	nullptr, wxID_ANY, _WINDOW_TITLE, wxDefaultPosition, wxSize(840, 480))
{
	constexpr int HSpacing		= 2;
	constexpr int VSpacing		= 2;
	constexpr int BorderWidth	= 5;
	constexpr int numOfRows		= 3;
	constexpr int numOfCols		= 2;

	wxPanel* background = new wxPanel(this, wxID_ANY);
	wxBoxSizer* bgBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* terminalBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* UIBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* selectionBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* chipViewBox = new wxBoxSizer(wxVERTICAL);

	wxMenuBar* menu = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(ID_REFRESH_COM_MENU, "&Refresh COM ports");
	fileMenu->Append(ID_REFRESH_TC_MENU, "Refresh test cases");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Quit");
	menu->Append(fileMenu, "File");

	Bind(wxEVT_MENU, &MainWindow::OnQuit, this, wxID_EXIT);

	wxStaticText* COMLabel = new wxStaticText(background, wxID_ANY, "COM selection");
	wxChoice* COMsel = new wxChoice(background, ID_COM_PORT_SEL);

	wxStaticText* tcLabel = new wxStaticText(background, wxID_ANY, "Test cases");
	wxListBox* tcList = new wxListBox(background, ID_TC_LIST);
	tcList->Append("peniz1");
	tcList->Append("peniz2");
	tcList->Append("peniz3");
	tcList->Append("peniz3");
	tcList->Append("RUN ALL");

	wxButton* selectButton = new wxButton(background, wxID_ANY, "Select");
	beginTestB = new wxButton(background, wxID_ANY, "Test!");
		
	/*wxNotebook* terminalWindow = new wxNotebook(background, ID_TERMINAL);
	wxTextCtrl* test2Text = new wxTextCtrl(terminalWindow, wxID_ANY, "Tu mo¿e byæ jakiœ uproszczony wynik testu");
	test2Text->SetWindowStyleFlag(wxTE_READONLY | wxTE_CENTRE);
	terminalWindow->AddPage(testText, "Terminal");
	terminalWindow->AddPage(test2Text, "Test results");*/
	wxRichTextCtrl* terminalWindow = new wxRichTextCtrl(
		background, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRE_READONLY | wxRE_MULTILINE);
	terminalWindow->SetBackgroundColour(wxColour(*wxBLACK));
	terminalWindow->SetDefaultStyle(wxTextAttr(*wxGREEN));
	terminalWindow->WriteText("[PASSED] ");
	terminalWindow->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
	terminalWindow->WriteText("Test output works!");
	wxStaticText* terminalLabel = new wxStaticText(background, wxID_ANY, "Test output");

	wxPanel* p4 = new wxPanel(background, wxID_ANY);
	p4->SetBackgroundColour(wxColor(0x00000a));

	buttonBox->Add(selectButton, 1, wxALL, BorderWidth);
	buttonBox->Add(beginTestB, 1, wxALL, BorderWidth);

	selectionBox->Add(COMLabel, 0, wxALIGN_CENTER_HORIZONTAL);
	selectionBox->Add(COMsel, 0, wxALIGN_CENTER_HORIZONTAL | wxEXPAND | wxLEFT | wxRIGHT, 14);
	selectionBox->Add(tcLabel, 0, wxALIGN_CENTER_HORIZONTAL);
	selectionBox->Add(tcList, 1, wxEXPAND | wxALL, BorderWidth);
	selectionBox->Add(buttonBox, 0,  wxALL | wxALIGN_CENTER , BorderWidth);
	selectionBox->Add(terminalLabel, 0,  wxALL | wxALIGN_LEFT , BorderWidth - 5);
	chipViewBox->Add(p4, 1, wxEXPAND | wxALL, BorderWidth);

	UIBox->Add(selectionBox, 1, wxEXPAND | wxALL, BorderWidth);
	UIBox->Add(chipViewBox, 2, wxEXPAND | (wxALL & ~wxBOTTOM), BorderWidth);

	terminalBox->Add(terminalWindow, 1, wxEXPAND | (wxALL & ~wxTOP), BorderWidth);

	bgBox->Add(UIBox, 3, wxEXPAND | (wxUP | wxRIGHT | wxLEFT), BorderWidth);
	bgBox->Add(terminalBox, 2, wxEXPAND | wxDOWN | wxRIGHT | wxLEFT, BorderWidth);

	background->SetSizer(bgBox);

	SetMenuBar(menu);
	Centre();
	SetMinClientSize(wxSize(400, 280));
	SetMaxClientSize(wxSize(841, 481));

}

void MainWindow::OnQuit(wxCommandEvent& evt)
{
	WXUNUSED(evt);
	Close(true);
}

} // namespace tb
