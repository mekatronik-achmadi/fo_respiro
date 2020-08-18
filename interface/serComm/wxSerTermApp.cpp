/***************************************************************
 * Name:      wxSerTermApp.cpp
 * Purpose:   Code for Application Class
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

#include "wxSerTermApp.h"
#include "wxSerTermMain.h"

IMPLEMENT_APP(wxSerTermApp);

bool wxSerTermApp::OnInit()
{
    wxSerTermFrame* frame = new wxSerTermFrame(0L);
    
    frame->Show();
    
    return true;
}
