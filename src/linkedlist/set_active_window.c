#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
set_active_window (const t_window_list *w)
{
        if (!w)
                return;

        XSetInputFocus(display->display, w->window->window,
                       RevertToPointerRoot, CurrentTime);
        XRaiseWindow(display->display, w->window->window);
}
