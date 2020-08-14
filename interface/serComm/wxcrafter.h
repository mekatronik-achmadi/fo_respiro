//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _WXGTK_SERCOMM_WXCRAFTER_BASE_CLASSES_H
#define _WXGTK_SERCOMM_WXCRAFTER_BASE_CLASSES_H

#include <wx/arrstr.h>
#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/menu.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/xrc/xmlres.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class MainFrameBaseClass : public wxFrame
{
protected:
    wxTextCtrl* m_txtCSV;
    wxTextCtrl* m_txtComm;
    wxTextCtrl* m_txtData;
    wxMenuBar* m_menuBar;
    wxMenu* m_mnFile;
    wxMenuItem* m_mnExit;
    wxMenu* m_mnHelp;
    wxMenuItem* m_mnAbout;
    wxToolBar* m_mainToolbar;
    wxButton* m_btnSerOpen;
    wxButton* m_btnSerTest;
    wxComboBox* m_cmbSerPort;

protected:
    virtual void OnExit(wxCommandEvent& event)
    {
	event.Skip();
    }
    virtual void OnAbout(wxCommandEvent& event)
    {
	event.Skip();
    }
    virtual void OnSerOpenClicked(wxCommandEvent& event)
    {
	event.Skip();
    }
    virtual void OnBtnSerTest(wxCommandEvent& event)
    {
	event.Skip();
    }
    virtual void OnCmbPortSelected(wxCommandEvent& event)
    {
	event.Skip();
    }

public:
    wxTextCtrl* GetTxtCSV()
    {
	return m_txtCSV;
    }
    wxTextCtrl* GetTxtComm()
    {
	return m_txtComm;
    }
    wxTextCtrl* GetTxtData()
    {
	return m_txtData;
    }
    wxMenuBar* GetMenuBar()
    {
	return m_menuBar;
    }
    wxButton* GetBtnSerOpen()
    {
	return m_btnSerOpen;
    }
    wxButton* GetBtnSerTest()
    {
	return m_btnSerTest;
    }
    wxComboBox* GetCmbSerPort()
    {
	return m_cmbSerPort;
    }
    wxToolBar* GetMainToolbar()
    {
	return m_mainToolbar;
    }
    MainFrameBaseClass(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxString& title = _("Mamad's Serial CSV"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(700, 500),
        long style = wxCAPTION | wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCLOSE_BOX);
    virtual ~MainFrameBaseClass();
};

#endif
