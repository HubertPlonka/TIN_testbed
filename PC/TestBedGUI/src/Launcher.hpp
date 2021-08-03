#pragma once

#include <wx/wx.h>
#include <memory>
#include "MainWindow.hpp"
#include "GUIManager.hpp"

namespace tb
{

class Launcher : public wxApp
{
public:
	virtual bool OnInit() override;

private:
	MainWindow* mainFrame;
	std::shared_ptr<GUIManager> managerInst;
};

} // namespace tb
