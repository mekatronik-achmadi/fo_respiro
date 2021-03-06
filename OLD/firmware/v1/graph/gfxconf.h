/******************************************************************************/
/* This file has been generated by the uGFX-Studio                            */
/*                                                                            */
/* http://ugfx.org                                                            */
/******************************************************************************/

#ifndef _GFXCONF_H
#define _GFXCONF_H

#define GFX_USE_OS_CHIBIOS TRUE

/********************************************************/
/* GDISP stuff                                          */
/********************************************************/
#define GFX_USE_GDISP TRUE
#define GDISP_NEED_CONTROL TRUE
#define GDISP_NEED_VALIDATION TRUE
#define GDISP_NEED_CLIP TRUE
#define GDISP_NEED_MULTITHREAD	TRUE
#define GDISP_DEFAULT_ORIENTATION GDISP_ROTATE_0
#define GDISP_NEED_PIXMAP TRUE

/********************************************************/
/* Font stuff                                           */
/********************************************************/


/********************************************************/
/* GWIN stuff                                           */
/********************************************************/
#define GFX_USE_GWIN TRUE
#define GWIN_NEED_WINDOWMANAGER	TRUE
#define GWIN_NEED_GRAPH TRUE


/********************************************************/
/* GTIMER stuff                                         */
/********************************************************/
#define GFX_USE_GTIMER TRUE
#define GTIMER_THREAD_PRIORITY NORMAL_PRIORITY
#define GTIMER_THREAD_WORKAREA_SIZE 2048

/********************************************************/
/* GINPUT stuff                                         */
/********************************************************/
#define GFX_USE_GINPUT FALSE


/********************************************************/
/* GEVENT stuff                                         */
/********************************************************/


/********************************************************/
/* GEVENT stuff                                         */
/********************************************************/


/********************************************************/
/* GFILE stuff                                          */
/********************************************************/


/********************************************************/
/* GMISC stuff                                          */
/********************************************************/


#endif /* _GFXCONF_H */
