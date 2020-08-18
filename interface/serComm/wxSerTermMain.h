/***************************************************************
 * Name:      wxSerTermMain.h
 * Purpose:   Defines Application Frame
 * Author:    Achmadi ST MT (mekatronik.achmadi@gmail.com)
 * Created:   2020-08-15
 * Copyright: Achmadi ST MT (http://github.com/mekatronik-achmadi/)
 * License:
 **************************************************************/

#ifndef WXSERTERMMAIN_H
#define WXSERTERMMAIN_H



#include "wxSerTermApp.h"


#include "GUIFrame.h"
#include <wx/timer.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <wx/arrstr.h>
#include <wx/filedlg.h>
#include "ceSerial.h"

class wxSerTermFrame: public GUIFrame
{
    public:
        wxSerTermFrame(wxFrame *frame);
        ~wxSerTermFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void onCmbPort(wxCommandEvent& event);
        virtual void OnTimerTick(wxTimerEvent& event);
        virtual void OnBtnOpen(wxCommandEvent& event);
        virtual void OnBtnTest(wxCommandEvent& event);
        virtual void OnBtnGetData(wxCommandEvent& event);
        virtual void OnBtnGetTable(wxCommandEvent& event);
        virtual void onBtnSaveTable(wxCommandEvent& event);
        virtual void OnBtnRunStop(wxCommandEvent& event);
        virtual char* wxstr2char(wxString& Text);
        virtual void OnCharReceive(char ch);
        virtual void cmbAddPort(void);

        ce::ceSerial *serComm;
        wxTimer *m_SerTimer;
        wxString devPort;
        wxString strRequest;
        wxString SaveCsvPath;
};

#endif // WXSERTERMMAIN_H
