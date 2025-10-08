#ifndef SWM_X11_HELPERS_H
#define SWM_X11_HELPERS_H

#include <X11/Xlib.h>
#include <X11/X.h>
#include "x11_data.h"

#define ERROR_BUFF_SIZE 256
#define X11_MASKS (KeyPressMask | KeyReleaseMask | PointerMotionMask |\
                   PropertyChangeMask | SubstructureRedirectMask |\
                   SubstructureNotifyMask)


extern x11_display x11_display_instance();
extern int x11_init_display (x11_display *dp);
extern int x11_free (x11_display *dp);
extern int x11_error_handler (Display *display, const XErrorEvent *event);
extern int x11_set_masks (const x11_display* screen);
extern void x11_main_loop(x11_display *dp);
extern GC x11_create_gc(x11_display *dp, Drawable d, unsigned long valuemask, XGCValues *values);

#endif
