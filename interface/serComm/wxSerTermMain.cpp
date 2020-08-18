/***************************************************************
 * Name:      wxSerTermMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Achmadi ST MT (mekatronik.achmadi@gmail.com)
 * Created:   2020-08-15
 * Copyright: Achmadi ST MT (http://github.com/mekatronik-achmadi/)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxSerTermMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxSerTermFrame::wxSerTermFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    serComm = new ce::ceSerial();
	serComm->SetBaudRate(9600);
	serComm->SetDataSize(8);
	serComm->SetParity('N');
	serComm->SetStopBits(1);
	serComm->SetDTR(false);
	serComm->SetRTS(false);

#ifdef ceWINDOWS
    devPort = "\\\\.\\COM1";
#else
    devPort = "/dev/ttyUSB0";
#endif // ceWINDOWS

	cmbAddPort();

	m_SerTimer = new wxTimer();
	m_SerTimer->Bind(wxEVT_TIMER,&wxSerTermFrame::OnTimerTick,this);

	m_btnOpen->SetLabel("Open");
    statusBar->SetStatusText("Closed: "+devPort+"-9600-8N1",1);
}

wxSerTermFrame::~wxSerTermFrame()
{
}

void wxSerTermFrame::OnClose(wxCloseEvent &event)
{
    if(serComm->IsOpened()){
        m_SerTimer->Stop();
		serComm->Close();
    }
    Destroy();
}

void wxSerTermFrame::OnQuit(wxCommandEvent &event)
{
    if(serComm->IsOpened()){
        m_SerTimer->Stop();
		serComm->Close();
    }
    Destroy();
}

void wxSerTermFrame::OnAbout(wxCommandEvent &event)
{
    wxAboutDialogInfo info;

	info.SetName("Serial Comm and CSV Output");
    info.SetCopyright(_("Achmadi ST MT @2020"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Serial Communication Interface and CSV Table Output"));

	wxAboutBox(info);
}

void wxSerTermFrame::onCmbPort(wxCommandEvent &event){
    devPort = m_cmbPort->GetValue();
    statusBar->SetStatusText("Port Selected: "+devPort,0);
}

void wxSerTermFrame::cmbAddPort(void){
#ifdef ceWINDOWS
    m_cmbPort->SetValue(_("\\\\.\\COM1"));
	m_cmbPort->Append(_("\\\\.\\COM1"));
	m_cmbPort->Append(_("\\\\.\\COM2"));
	m_cmbPort->Append(_("\\\\.\\COM3"));
	m_cmbPort->Append(_("\\\\.\\COM4"));
	m_cmbPort->Append(_("\\\\.\\COM5"));
	m_cmbPort->Append(_("\\\\.\\COM6"));
#else
    m_cmbPort->SetValue(_("/dev/ttyUSB0"));
	m_cmbPort->Append(_("/dev/ttyUSB0"));
	m_cmbPort->Append(_("/dev/ttyUSB1"));
	m_cmbPort->Append(_("/dev/ttyUSB2"));
	m_cmbPort->Append(_("/dev/ttyACM0"));
	m_cmbPort->Append(_("/dev/ttyACM1"));
	m_cmbPort->Append(_("/dev/ttyACM2"));
#endif
}

void wxSerTermFrame::OnTimerTick(wxTimerEvent& event){
    char chr;
    bool receive;

    do{
        chr = serComm->ReadChar(receive);
        if(receive) OnCharReceive(chr);
    }while(receive);
}

void wxSerTermFrame::OnCharReceive(char ch){
    m_txtComm->AppendText(wxString::Format(wxT("%c"), ch));
}

char* wxSerTermFrame::wxstr2char(wxString& Text){
    std::string strBuff = Text.ToStdString();

	int size = strBuff.size();
	char *a = new char[size + 1];
	a[strBuff.size()] = 0;
	memcpy(a, Text.c_str(), size);
	return a;
}

void wxSerTermFrame::OnBtnOpen(wxCommandEvent& event){
    if(m_btnOpen->GetLabel()=="Open"){

        serComm->SetComPort(devPort.ToStdString());

        if(serComm->Open()==0){
            m_btnOpen->SetLabel("Close");
            statusBar->SetStatusText("Opened: "+devPort+"-9600-8N1",1);
            m_SerTimer->Start(10);
        }
        else{
            m_btnOpen->SetLabel("Open");
            statusBar->SetStatusText("Failed: "+devPort+"-9600-8N1",1);
            m_SerTimer->Stop();
        }
    }
    else{
        serComm->Close();
		m_btnOpen->SetLabel("Open");
		statusBar->SetStatusText("Closed: "+devPort+"-9600-8N1",1);
		m_SerTimer->Stop();
    }
}

void wxSerTermFrame::OnBtnTest(wxCommandEvent& event){
    if(serComm->IsOpened()){
		strRequest = wxT("test\r\n");
		serComm->Write(wxstr2char(strRequest));
		statusBar->SetStatusText(strRequest+"sent",0);
		m_txtComm->Clear();
	}
	else{
        statusBar->SetStatusText("Port"+devPort+" is not opened",0);
	}
}

void wxSerTermFrame::OnBtnGetData(wxCommandEvent& event){
    if(serComm->IsOpened()){
		strRequest = wxT("real\r\n");
		serComm->Write(wxstr2char(strRequest));
		statusBar->SetStatusText(strRequest+"sent",0);
        m_txtComm->Clear();
	}
	else{
        statusBar->SetStatusText("Port"+devPort+" is not opened",0);
	}
}

void wxSerTermFrame::OnBtnGetTable(wxCommandEvent& event){
    wxString serData = m_txtComm->GetValue();

    serData.Replace('[',' ',true);
    serData.Replace(']',' ',true);
    serData.Replace(';','\n',true);

    m_txtCSV->Clear();
    m_txtCSV->AppendText(serData);
}

void wxSerTermFrame::onBtnSaveTable(wxCommandEvent& event){
    wxFileDialog *SaveDialog = new wxFileDialog(
                                                this,
                                                _("Save CSV to"),
                                                wxEmptyString,
                                                wxEmptyString,
                                                _("CSV File (*.csv)|*.csv"),
                                                wxFD_SAVE,
                                                wxDefaultPosition);

    if(SaveDialog->ShowModal()==wxID_OK){
        SaveCsvPath = SaveDialog->GetPath();
#ifdef ceLINUX
        SaveCsvPath = SaveCsvPath + ".csv";
#endif // ceLINUX
        statusBar->SetStatusText("Saved as: "+SaveCsvPath);
        m_txtCSV->SaveFile(SaveCsvPath);
    }
}

void wxSerTermFrame::OnBtnRunStop(wxCommandEvent& event){
    if(serComm->IsOpened()){
        m_txtComm->Clear();
        if(m_btnRunStop->GetLabel()=="Stop"){
            strRequest = wxT("stop\r\n");
            serComm->Write(wxstr2char(strRequest));
            statusBar->SetStatusText(strRequest+"sent",0);
            m_btnRunStop->SetLabel("Run");
        }
        else{
            strRequest = wxT("run\r\n");
            serComm->Write(wxstr2char(strRequest));
            statusBar->SetStatusText(strRequest+"sent",0);
            m_btnRunStop->SetLabel("Stop");
        }
    }
}


