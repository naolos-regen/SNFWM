#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
goto_window_number (int n)
{
        snfwm_window *win;

        if ((win = list_at (dpy->head, n)) == NULL)
        {
                return;
        }
        dpy->current = win;
        set_active_window(dpy->current);
}
