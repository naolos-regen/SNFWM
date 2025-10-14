#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"

void
destroy_notify(const XEvent *event)
{
    snfwm_screen *s;
    t_window_list *w;

    s  = find_screen(event->xdestroywindow.window);
    w  = list_find_window(dpy->head, event->xdestroywindow.window);

    if (s && w)
    {
        log_debug("time to destroy a window");
        if (w->window->state == STATE_UNMAPPED) last_window ();
        unmanage(w->window);
    }
}
