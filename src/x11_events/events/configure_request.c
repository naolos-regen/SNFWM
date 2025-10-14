#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_data.h"

void 
configure_request(const XEvent *event)
{
        XConfigureRequestEvent *ev;
        XConfigureEvent ce;
        t_window_list   *w;

        ev = (XConfigureRequestEvent *) ev;
        w  = list_find_window(dpy->head, ev->window);

        if (w)
        {
                ce.type = ConfigureNotify;
                ce.event = ev->window;
                ce.window = ev->window;
                ce.x = 0;
                ce.y = 0;
                ce.width = w->window->screen->attr_root.width;
                ce.height = w->window->screen->attr_root.height;
                ce.border_width = 0;
                ce.above = None;
                ce.override_redirect = 0;
                if (ev->value_mask & CWStackMode && w->window->state == STATE_MAPPED)
                {
                        dpy->current = w;
                        set_active_window(dpy->current);
                }
                else if (ev->detail == Below && w == dpy->current)
                {
                        last_window ();
                }

                XSendEvent(dpy->display, w->window->window, False, SubstructureNotifyMask, (XEvent *)&ce);
        }
}
