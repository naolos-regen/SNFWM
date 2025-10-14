#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
set_current_window (t_window_list *win)
{
        dpy->current = win;
}
