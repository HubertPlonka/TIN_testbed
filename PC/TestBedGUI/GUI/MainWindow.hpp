#pragma once

#include <wx/wx.h>

namespace tb
{

enum WidgetID : int
{
	unused = 1000,
	ID_BEGIN_TEST_BUTTON,
	ID_TC_LIST
};

class MainWindow : public wxFrame
{
public:
	MainWindow();

private:
	wxButton* beginTestB = nullptr;

};

} // namespace tb
