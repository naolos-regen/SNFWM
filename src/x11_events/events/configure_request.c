#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"

void configure_request(const XEvent *event)
{
        XConfigureRequestEvent *ev;
        x11_display    *dp;
        XConfigureEvent ce;
        t_window_list   *w;

        ev = (XConfigureRequestEvent *) ev;
        dp = x11_display_instance();
        w  = list_find_window(dp->head, ev->window);

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
                        dp->current = w;
                        set_active_window(dp->current);
                }
                else if (ev->detail == Below && w == dp->current)
                {
                        last_window ();
                }

                XSendEvent(dp->display, w->window->window, False, SubstructureNotifyMask, (XEvent *)&ce);
        }
}
