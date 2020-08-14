#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/timer.h>
#include "wxcrafter.h"
#include "ceSerial.h"

class MainFrame : public MainFrameBaseClass
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	void OnTimerTick(wxTimerEvent& event);
	void AddPort(void);
	void ProcessChar(char ch);
	char* wxstr2char(wxString& Text);
	
	ce::ceSerial *serComm;
	wxString devPort;
	wxString strRequest;
	wxTimer *m_SerTimer;
	int sttSerOpen;
	
protected:
    virtual void OnBtnSerTest(wxCommandEvent& event);
    virtual void OnSerOpenClicked(wxCommandEvent& event);
    virtual void OnCmbPortSelected(wxCommandEvent& event);
};
#endif // MAINFRAME_H
