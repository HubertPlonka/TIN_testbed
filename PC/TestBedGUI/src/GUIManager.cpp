#include "GUIManager.hpp"

// kinda cheaty way to make everything work, functions used by wxWidgets are 
// deprecated thus VS complains about it
#pragma warning(disable : 4996)
#include "MainWindow.hpp"

#include <cstdio>

namespace tb
{
    // #doinWhatICanNotToIncludeWxWidgetsInHpp
    static void PrintConsole(
        const std::string& message,
        LogLevel llvl,
        const wxColour* color)
    {
        wxRichTextCtrl* terminal = MainWindow::GetInstance()->GetTerminal();
        char logPrefix[20];
        std::string logLabel;

        switch (llvl)
        {
        case LogLevel::INFO:
            sprintf_s(logPrefix, "[INFO]\t\t");
            break;
        case LogLevel::ERR:
            sprintf_s(logPrefix, "[ERROR]\t");
            break;
        case LogLevel::DEBUG:
            sprintf_s(logPrefix, "[DEBUG]\t");
            break;
        }

        logLabel = logPrefix;

        terminal->SetDefaultStyle(wxTextAttr(*color));
        terminal->WriteText(logLabel);
        terminal->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
        terminal->WriteText(message);
        terminal->Newline();
    }

    void GUIManager::SetLoggingLevel(const LogLevel llvl)
    {
        logLvl.set((unsigned)llvl);
    }

    void GUIManager::PrintConsoleInfo(const std::string& message)
    {
        if (logLvl.test((unsigned)LogLevel::INFO))
            PrintConsole(message, LogLevel::INFO, wxWHITE);
    }

    void GUIManager::PrintConsoleError(const std::string& message)
    {
        if (logLvl.test((unsigned)LogLevel::ERR))
            PrintConsole(message, LogLevel::ERR, wxRED);
    }

    void GUIManager::PrintConsoleDebug(const std::string& message)
    {
        if (logLvl.test((unsigned)LogLevel::DEBUG))
            PrintConsole(message, LogLevel::DEBUG, wxYELLOW);
    }

    void GUIManager::PrintTestState(const std::string& message, const TestResult result)
    {
        wxRichTextCtrl* terminal = MainWindow::GetInstance()->GetTerminal();
        char labelBuff[15] = { 0 };

        if (result == TestResult::PASS)
        {
            sprintf_s(labelBuff, "[PASSED]\t");
            terminal->SetDefaultStyle(wxTextAttr(*wxGREEN));
            terminal->WriteText(labelBuff);
        }
        else
        {
            sprintf_s(labelBuff, "[FAILED]\t");
            terminal->SetDefaultStyle(wxTextAttr(*wxRED));
            terminal->WriteText(labelBuff);
        }

        terminal->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
        terminal->WriteText(message);
        terminal->Newline();
    }

} // namespace tb