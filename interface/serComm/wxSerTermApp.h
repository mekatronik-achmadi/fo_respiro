/***************************************************************
 * Name:      wxSerTermApp.h
 * Purpose:   Defines Application Class
 * Author:    Achmadi ST MT (mekatronik.achmadi@gmail.com)
 * Created:   2020-08-15
 * Copyright: Achmadi ST MT (http://github.com/mekatronik-achmadi/)
 * License:
 **************************************************************/

#ifndef WXSERTERMAPP_H
#define WXSERTERMAPP_H

#include <wx/app.h>

class wxSerTermApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXSERTERMAPP_H
