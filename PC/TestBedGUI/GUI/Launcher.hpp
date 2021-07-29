#pragma once

#include <wx/wx.h>
#include "MainWindow.hpp"

namespace tb
{

class Launcher : public wxApp
{
public:
	virtual bool OnInit() override;

private:
	MainWindow* mainFrame = nullptr;
};

} // namespace tb
