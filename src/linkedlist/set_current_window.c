#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
set_current_window (snfwm_window *win)
{
        dpy->current = win;
}
