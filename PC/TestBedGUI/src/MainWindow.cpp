#include "MainWindow.hpp"
#include "GUIManager.hpp"
#include "SerialCom.hpp"

namespace tb
{
	constexpr char _WINDOW_TITLE[] = "AVR TestBed v" AVR_TB_VERSION; 

	MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow() : wxFrame(
	nullptr, wxID_ANY, _WINDOW_TITLE, wxDefaultPosition, wxSize(840, 480))
{
	if (instance == nullptr)
	{
		instance = this;
	}
	else
	{
		return;
	}

	constexpr int HSpacing		= 2;
	constexpr int VSpacing		= 2;
	constexpr int BorderWidth	= 5;
	constexpr int numOfRows		= 3;
	constexpr int numOfCols		= 2;

	wxPanel* background			= new wxPanel(this, wxID_ANY);
	wxBoxSizer* bgBox			= new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* terminalBox		= new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* UIBox			= new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* selectionBox	= new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonBox		= new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* chipViewBox		= new wxBoxSizer(wxVERTICAL);

	////////////////////////////////////////////////////////////////
	// Menu on top ribbon
	////////////////////////////////////////////////////////////////

	wxMenuBar* menu = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(ID_PROGRAM_AVR_MENU, "Program AVR");
	fileMenu->Append(ID_REFRESH_COM_MENU, "&Refresh COM ports");
	fileMenu->Append(ID_REFRESH_TC_MENU, "Refresh test cases");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Quit");
	menu->Append(fileMenu, "File");

	Bind(wxEVT_MENU, &MainWindow::OnQuit, this, wxID_EXIT);
	//Bind();

	////////////////////////////////////////////////////////////////
	// COM port selection field
	////////////////////////////////////////////////////////////////

	wxStaticText* COMLabel = new wxStaticText(background, wxID_ANY, "COM selection");
	COMsel = new wxChoice(background, ID_COM_PORT_SEL);

	////////////////////////////////////////////////////////////////
	// Test case selection area
	////////////////////////////////////////////////////////////////

	wxStaticText* tcLabel = new wxStaticText(background, wxID_ANY, "Test cases");
	tcList = new wxListBox(background, ID_TC_LIST);
	tcList->Append("test1");
	tcList->Append("test2");
	tcList->Append("test3");
	tcList->Append("test3");
	tcList->Append("RUN ALL");

	selectButton = new wxButton(background, ID_SELECT_BUTTON, "Select");
	beginTestB = new wxButton(background, ID_BEGIN_TEST_BUTTON, "Test!");

	////////////////////////////////////////////////////////////////
	// "Terminal" window (displays info about tests)
	////////////////////////////////////////////////////////////////

	terminalWindow = new wxRichTextCtrl(
		background, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRE_READONLY | wxRE_MULTILINE);
	terminalWindow->SetBackgroundColour(wxColour(*wxBLACK));
	terminalWindow->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
	terminalWindow->WriteText("======= ");
	terminalWindow->WriteText(_WINDOW_TITLE);
	terminalWindow->WriteText(" =======");
	terminalWindow->Newline();
	wxStaticText* terminalLabel = new wxStaticText(background, wxID_ANY, "Test output");

	////////////////////////////////////////////////////////////////
	// Unused - this might be chip visualisation in the future 
	// also this may be replaced by bigger terminal window
	////////////////////////////////////////////////////////////////

	wxPanel* p4 = new wxPanel(background, wxID_ANY);
	p4->SetBackgroundColour(wxColor(0x00000a));

	////////////////////////////////////////////////////////////////
	// Layout management (plz don't touch :))
	////////////////////////////////////////////////////////////////

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

	tcmInst = std::make_shared<TCManager>(TCManager());
	tcmInst->TestConsoleOut();

	Bind(wxEVT_BUTTON, &MainWindow::OnTCSelected, this, ID_SELECT_BUTTON);
	Bind(wxEVT_BUTTON, &MainWindow::OnTestBegin, this, ID_BEGIN_TEST_BUTTON);
	Bind(wxEVT_MENU, &MainWindow::OnRefreshCOMtable, this, ID_REFRESH_COM_MENU);
}

void MainWindow::OnRefreshCOMtable(wxCommandEvent& evt)
{
	SerialCom::RefreshAvailableCOMPorts();
	GUIManager::PrintConsoleDebug("Refreshowanie dziala :)");
	evt.Skip();
}

void MainWindow::OnRefreshTCtable(wxCommandEvent& evt)
{
	// Here should be invoked func which parses txt and 
	// creates new txts
}

void MainWindow::OnTestBegin(wxCommandEvent& evt)
{
	tcmInst->RunTestCase((const char*)tcList->GetStringSelection());
	evt.Skip();
}

void MainWindow::OnTCSelected(wxCommandEvent& evt)
{
	std::string tcName{};
	tcName = tcList->GetStringSelection();

	if (tcName.empty())
	{
		GUIManager manager;
		manager.PrintConsoleInfo("Select test case on list before clicking \"Select\"");
		evt.Skip();
		return;
	}

	tcmInst->RunTestCase(tcName);
	evt.Skip();
}

void MainWindow::OnQuit(wxCommandEvent& evt)
{
	WXUNUSED(evt);
	Close(true);
}

} // namespace tb
