#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_jobs.h"

/* TODO: What needs to be implemented is sort of a way to store all windows/screens 
 *       and find corresponding window that we try to remove using XDestroyNotifyEvent
 *       so first of all i need to create a list innit 
 */
void destroy_notify(const XEvent *event)
{
    x11_display *dp;
    snfwm_screen *s;
    t_window_list *w;

    dp = x11_display_instance();
    s  = find_screen(event->xdestroywindow.window);
    w  = list_find_window(dp->head, event->xdestroywindow.window);

    if (s && w)
    {
        log_debug("time to destroy a window");
        if (w->window->state == STATE_UNMAPPED) last_window ();
        unmanage(w->window);
    }
}
