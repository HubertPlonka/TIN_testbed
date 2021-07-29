#include "MainWindow.hpp"


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

	wxListBox* tcList = new wxListBox(background, ID_TC_LIST);
	tcList->Append("peniz1");
	wxButton* selectButton = new wxButton(background, wxID_ANY, "Select");
	beginTestB = new wxButton(background, wxID_ANY, "Test!");


	//wxPanel* p1 = new wxPanel(background, wxID_ANY);
	//p1->SetBackgroundColour(wxColor(0xff0000));
	//wxPanel* p2 = new wxPanel(background, wxID_ANY);
	//p2->SetBackgroundColour(wxColor(0x00ff00));
	wxPanel* p3 = new wxPanel(background, wxID_ANY);
	p3->SetBackgroundColour(wxColor(0x0000ff));
	wxPanel* p4 = new wxPanel(background, wxID_ANY);
	p4->SetBackgroundColour(wxColor(0x00000a));


	buttonBox->Add(selectButton, 1, wxALL, BorderWidth);
	buttonBox->Add(beginTestB, 1, wxALL, BorderWidth);

	selectionBox->Add(tcList, 1, wxEXPAND | wxALL, BorderWidth);
	selectionBox->Add(buttonBox, 0,  wxALL | wxALIGN_CENTER , BorderWidth);
	chipViewBox->Add(p4, 1, wxEXPAND | wxALL, BorderWidth);

	UIBox->Add(selectionBox, 1, wxEXPAND | wxALL, BorderWidth);
	UIBox->Add(chipViewBox, 2, wxEXPAND | wxALL, BorderWidth);

	terminalBox->Add(p3, 1, wxEXPAND | wxALL, BorderWidth);

	bgBox->Add(UIBox, 3, wxEXPAND | (wxUP | wxRIGHT | wxLEFT), BorderWidth);
	bgBox->Add(terminalBox, 2, wxEXPAND | wxDOWN | wxRIGHT | wxLEFT, BorderWidth);

	background->SetSizer(bgBox);

	Centre();
	SetMinClientSize(wxSize(400, 280));
	SetMaxClientSize(wxSize(841, 481));

}

} // namespace tb
