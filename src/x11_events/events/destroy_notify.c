#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
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

        if (!win)
        {
                log_debug("DestroyNotify for unmanaged window 0x%1x", event->xdestroywindow.window);
                return;
        }

        log_debug("DestroyNotify for 0x%1x", win->window);

        if (dpy->current == win)
                dpy->current = NULL;
        unmanage(win);

        while (more_destroy_events())
        {
                XEvent dm;
                XNextEvent(dpy->display, &dm);
                log_debug("skipping extra destroynotify for window 0x%1x", dm.xdestroywindow.event);
        }

        if (dpy->current == NULL && dpy->head)
        {
                dpy->current = dpy->head;
                log_debug("Switched focus to 0x%1x", dpy->current->window);
                XWindowAttributes attrs;
                if (XGetWindowAttributes(dpy->display, dpy->current->window, &attrs))
                        set_active_window(dpy->current);
                else
                        log_warn("Head window 0x%1x is already gone", dpy->current->window);
        }
}
