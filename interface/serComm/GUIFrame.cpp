///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 14 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 700,700 ), wxDefaultSize );

	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );

	mbar->Append( fileMenu, wxT("&File") );

	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );

	mbar->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( mbar );

	m_barMain = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_btnOpen = new wxButton( m_barMain, wxID_ANY, wxT("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnOpen );
	m_btnTest = new wxButton( m_barMain, wxID_ANY, wxT("Test"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnTest );
	m_cmbPort = new wxComboBox( m_barMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_barMain->AddControl( m_cmbPort );
	m_btnRunStop = new wxButton( m_barMain, wxID_ANY, wxT("Stop Chip"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnRunStop );
	m_btnGetData = new wxButton( m_barMain, wxID_ANY, wxT("Get Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnGetData );
	m_btnGetTable = new wxButton( m_barMain, wxID_ANY, wxT("Get Table"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnGetTable );
	m_btnSaveTable = new wxButton( m_barMain, wxID_ANY, wxT("Save Table"), wxDefaultPosition, wxDefaultSize, 0 );
	m_barMain->AddControl( m_btnSaveTable );
	m_barMain->Realize();

	wxBoxSizer* bView;
	bView = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bCSV;
	bCSV = new wxBoxSizer( wxVERTICAL );

	m_lblCSV = new wxStaticText( this, wxID_ANY, wxT("CSV Table"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_lblCSV->Wrap( -1 );
	bCSV->Add( m_lblCSV, 0, wxALL|wxEXPAND, 5 );

	m_txtCSV = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP|wxTE_MULTILINE|wxTE_READONLY );
	bCSV->Add( m_txtCSV, 1, wxALL|wxEXPAND, 5 );


	bView->Add( bCSV, 1, wxEXPAND, 5 );

	wxBoxSizer* bComm;
	bComm = new wxBoxSizer( wxVERTICAL );

	m_lblSerial = new wxStaticText( this, wxID_ANY, wxT("Serial Buffer"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_lblSerial->Wrap( -1 );
	bComm->Add( m_lblSerial, 0, wxALL|wxEXPAND, 5 );

	m_txtComm = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP|wxTE_MULTILINE|wxTE_READONLY );
	bComm->Add( m_txtComm, 1, wxALL|wxEXPAND, 5 );


	bView->Add( bComm, 1, wxEXPAND, 5 );


	this->SetSizer( bView );
	this->Layout();
	statusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ), this, menuFileQuit->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ), this, menuHelpAbout->GetId());
	m_btnOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnOpen ), NULL, this );
	m_btnTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnTest ), NULL, this );
	m_cmbPort->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIFrame::onCmbPort ), NULL, this );
	m_btnRunStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnRunStop ), NULL, this );
	m_btnGetData->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnGetData ), NULL, this );
	m_btnGetTable->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnGetTable ), NULL, this );
	m_btnSaveTable->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnSaveTable ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	m_btnOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnOpen ), NULL, this );
	m_btnTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnTest ), NULL, this );
	m_cmbPort->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIFrame::onCmbPort ), NULL, this );
	m_btnRunStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnRunStop ), NULL, this );
	m_btnGetData->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnGetData ), NULL, this );
	m_btnGetTable->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnBtnGetTable ), NULL, this );
	m_btnSaveTable->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnSaveTable ), NULL, this );

}
