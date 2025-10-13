#include "../../include/linkedlist.h"
#include <X11/Xlib.h>
#include <stdlib.h>
#include "../../include/x11_helpers.h"

void
free_window(snfwm_window *window)
{
        x11_display *display = x11_display_instance();
        if (!window || !display->display)
                return;
        if (window->window)
                XDestroyWindow(display->display, window->window);
        free(window->window_name);
        free( window);
}
