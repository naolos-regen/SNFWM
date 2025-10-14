#include "../../include/linkedlist.h"
#include "../../include/bar.h"
#include "../../include/x11_data.h"

void
set_active_window (t_window_list *w)
{
        static int counter = 1;
        
        if (!w)
                return;
        counter = counter + 1;
        w->window->last_access = counter;

        if (w->window->screen->bar_raised) update_window_names(w->window->screen);
        XSetInputFocus(dpy->display, w->window->window,
                       RevertToPointerRoot, CurrentTime);
        XRaiseWindow(dpy->display, w->window->window);
}
