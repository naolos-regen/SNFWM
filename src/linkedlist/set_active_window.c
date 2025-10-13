#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"
#include "../../include/bar.h"

void
set_active_window (t_window_list *w)
{
        static int counter = 1;
        
        if (!w)
                return;
        counter = counter + 1;
        w->window->last_access = counter;

        if (w->window->screen->bar_raised) update_window_names(w->window->screen);

        x11_display *display = x11_display_instance();
        XSetInputFocus(display->display, w->window->window,
                       RevertToPointerRoot, CurrentTime);
        XRaiseWindow(display->display, w->window->window);
}
