#ifndef SWM_X11_HELPERS_H
#define SWM_X11_HELPERS_H

#include <X11/Xlib.h>

#define ERROR_BUFF_SIZE 256
#define X11_MASKS (KeyPressMask | KeyReleaseMask | PointerMotionMask |\
                   PropertyChangeMask | SubstructureRedirectMask |\
                   SubstructureNotifyMask)

#define x11_display struct x11_dp

struct x11_dp
{
	Display* display;
	Window root;
};

extern int x11_init_display(x11_display* dp);
extern int x11_free(const x11_display* display);
extern int x11_error_handler(Display* display, const XErrorEvent* event);
extern int x11_set_masks(const x11_display* screen);


#endif
