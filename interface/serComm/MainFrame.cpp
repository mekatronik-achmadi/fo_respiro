#include "MainFrame.h"
#include <wx/aboutdlg.h>

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBaseClass(parent)
{
	sttSerOpen = 0;
	if(sttSerOpen==0){
		m_btnSerOpen->SetLabel("Open");
	}
	
	serComm = new ce::ceSerial();
	serComm->SetBaudRate(9600);
	serComm->SetDataSize(8);
	serComm->SetParity('N');
	serComm->SetStopBits(1);
	serComm->SetDTR(false);
	serComm->SetRTS(false);
	
	m_SerTimer = new wxTimer();
	m_SerTimer->Bind(wxEVT_TIMER,&MainFrame::OnTimerTick,this);
	
	AddPort();
}

MainFrame::~MainFrame()
{
}

void MainFrame::AddPort(){
#ifdef ceWINDOWS
	m_cmbSerPort->Append(_("\\\\.\\COM1"));
	m_cmbSerPort->Append(_("\\\\.\\COM2"));
	m_cmbSerPort->Append(_("\\\\.\\COM3"));
	m_cmbSerPort->Append(_("\\\\.\\COM4"));
	m_cmbSerPort->Append(_("\\\\.\\COM5"));
	m_cmbSerPort->Append(_("\\\\.\\COM6"));
#else
	m_cmbSerPort->Append(_("/dev/ttyUSB0"));
	m_cmbSerPort->Append(_("/dev/ttyUSB1"));
	m_cmbSerPort->Append(_("/dev/ttyUSB2"));
	m_cmbSerPort->Append(_("/dev/ttyACM0"));
	m_cmbSerPort->Append(_("/dev/ttyACM1"));
	m_cmbSerPort->Append(_("/dev/ttyACM2"));
#endif
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
	if(serComm->IsOpened()){
		m_SerTimer->Stop();
		serComm->Close();
	}
    Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxUnusedVar(event);
    wxAboutDialogInfo info;
	
	info.SetName("Serial Comm and CSV Output");
    info.SetCopyright(_("Achmadi ST MT @2020"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Serial Communication Interface and CSV Table Output"));
    
	::wxAboutBox(info);
}

void MainFrame::OnCmbPortSelected(wxCommandEvent& event)
{
	devPort = m_cmbSerPort->GetValue();
	m_txtComm->AppendText("Port: "+devPort+"\r\n");
}

void MainFrame::OnSerOpenClicked(wxCommandEvent& event)
{
	
if(sttSerOpen == 0){
	serComm->SetPort(std::string(devPort.mb_str()));
	if(serComm->Open()==0){
		sttSerOpen = 1;
		m_btnSerOpen->SetLabel("Close");
		m_txtComm->AppendText("Opened at "+devPort+"\r\n");
		m_SerTimer->Start(100);
	}
	else{
		sttSerOpen = 0;
		m_btnSerOpen->SetLabel("Open");
		m_txtComm->AppendText("Failed at "+devPort+"\r\n");
		m_SerTimer->Stop();
	}
}
else{
	if(serComm->IsOpened()){
		serComm->Close();
		sttSerOpen = 0;
		m_btnSerOpen->SetLabel("Open");
		m_txtComm->AppendText("Closed at "+devPort+"\r\n");
		m_SerTimer->Stop();
	}
}
	
}

void MainFrame::OnTimerTick(wxTimerEvent& event){
	char ch;
	bool r;
	
	do {
		ch = serComm->ReadChar(r);
		if (r) ProcessChar(ch);}
	while(r);
}

void MainFrame::ProcessChar(char ch){
	m_txtComm->AppendText(wxString::Format(wxT("%c"), ch));
}

void MainFrame::OnBtnSerTest(wxCommandEvent& event)
{
	if(serComm->IsOpened()){
		strRequest = wxT("test\r\n");
		serComm->Write(wxstr2char(strRequest));
	}
	else{
		m_txtComm->AppendText("Port "+devPort+" is not opened\r\n");
	}
}

char* MainFrame::wxstr2char(wxString& Text){
	std::string strBuff = std::string(Text.mb_str());
	
	int size = strBuff.size();
	char *a = new char[size + 1];
	a[strBuff.size()] = 0;
	memcpy(a, Text.c_str(), size);
	return a;
}
