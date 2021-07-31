#include "MainWindow.hpp"
#include "wx/notebook.h"


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
		
	wxNotebook* terminalWindow = new wxNotebook(background, ID_TERMINAL);
	wxTextCtrl* testText = new wxTextCtrl(terminalWindow, wxID_ANY, "Tu moga sie wyswietlac wykonywane polecenia");
	wxTextCtrl* test2Text = new wxTextCtrl(terminalWindow, wxID_ANY, "Tu mo¿e byæ jakiœ uproszczony wynik testu");
	terminalWindow->AddPage(testText, "Terminal");
	terminalWindow->AddPage(test2Text, "Test results");

	wxPanel* p4 = new wxPanel(background, wxID_ANY);
	p4->SetBackgroundColour(wxColor(0x00000a));


	buttonBox->Add(selectButton, 1, wxALL, BorderWidth);
	buttonBox->Add(beginTestB, 1, wxALL, BorderWidth);


	selectionBox->Add(COMLabel, 0, wxALIGN_CENTER_HORIZONTAL);
	selectionBox->Add(COMsel, 0, wxALIGN_CENTER_HORIZONTAL | wxEXPAND);
	selectionBox->Add(tcLabel, 0, wxALIGN_CENTER_HORIZONTAL);
	selectionBox->Add(tcList, 1, wxEXPAND | wxALL, BorderWidth);
	selectionBox->Add(buttonBox, 0,  wxALL | wxALIGN_CENTER , BorderWidth);
	chipViewBox->Add(p4, 1, wxEXPAND | wxALL, BorderWidth);

	UIBox->Add(selectionBox, 1, wxEXPAND | wxALL, BorderWidth);
	UIBox->Add(chipViewBox, 2, wxEXPAND | wxALL, BorderWidth);

	terminalBox->Add(terminalWindow, 1, wxEXPAND | wxALL, BorderWidth);

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
