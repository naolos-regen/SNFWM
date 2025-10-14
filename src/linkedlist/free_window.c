#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"
#include <X11/Xlib.h>
#include <stdlib.h>

void
free_window(snfwm_window *window)
{
        if (!window || !dpy->display)
                return;
        if (window->window)
                XDestroyWindow(dpy->display, window->window);
        free(window->window_name);
        free( window);
}
