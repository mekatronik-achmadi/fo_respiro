///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 14 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxToolBar* m_barMain;
		wxButton* m_btnOpen;
		wxButton* m_btnTest;
		wxComboBox* m_cmbPort;
		wxButton* m_btnRunStop;
		wxButton* m_btnGetData;
		wxButton* m_btnGetTable;
		wxButton* m_btnSaveTable;
		wxStaticText* m_lblCSV;
		wxTextCtrl* m_txtCSV;
		wxStaticText* m_lblSerial;
		wxTextCtrl* m_txtComm;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCmbPort( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnRunStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnGetData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnGetTable( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBtnSaveTable( wxCommandEvent& event ) { event.Skip(); }


	public:

		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serial and CSV Output"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,700 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~GUIFrame();

};

