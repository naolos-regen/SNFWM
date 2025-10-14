#ifndef SWM_X11_HELPERS_H
#define SWM_X11_HELPERS_H

#include <X11/Xlib.h>
#include <X11/X.h>
#include "x11_data.h"

#define ERROR_BUFF_SIZE 256
#define X11_MASKS (KeyPressMask | KeyReleaseMask | PointerMotionMask |\
                   PropertyChangeMask | SubstructureRedirectMask |\
                   SubstructureNotifyMask)


extern int x11_free ();
extern int x11_set_masks ();
extern void x11_main_loop();
extern snfwm_screen *find_screen(Window window);

#endif
