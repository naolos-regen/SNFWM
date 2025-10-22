#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"

int
more_destroy_events ()
{
        XEvent ev;
        if (XCheckTypedEvent(dpy->display, DestroyNotify, &ev))
        {
                XPutBackEvent(dpy->display, &ev);
                return (1);
        }
        return (0);
}

void
destroy_notify(const XEvent *event)
{
        static int switch_window_pending = 0;
        int last_destroy_event;
        snfwm_window *win;

        win = list_find_window(dpy->head, event->xdestroywindow.event);

        last_destroy_event = !more_destroy_events();
        if (win)
        {
                if (win == dpy->current)
                {
                        log_debug("Destroying current window");
                        if (!last_destroy_event) switch_window_pending = 1;
                        unmanage(win);
                }
                else 
                {
                        log_debug("Destroying  some other window");
                        unmanage(win);
                }
        }
}
