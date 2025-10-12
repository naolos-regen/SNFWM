#include "../../include/linkedlist.h"
#include <X11/Xlib.h>
#include <stdlib.h>

void
free_window(const snfwm_window *window)
{
        if (!window || !display->display)
                return;
        XDestroyWindow(display->display, window->window);
        free((snfwm_window *) window);
}
