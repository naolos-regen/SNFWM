#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_data.h"
#include "../../../include/logger.h"

void 
configure_request(const XEvent *event)
{
        XConfigureRequestEvent *ev;
        XConfigureEvent ce;
        snfwm_window   *w;

        ev = (XConfigureRequestEvent *) event;
        log_warn("we try to find the window from event");
        w  = list_find_window(dpy->head, ev->window);
        log_warn("we hit the configure_request");
        if (w)
        {
                ce.type = ConfigureNotify;
                ce.event = ev->window;
                ce.window = ev->window;
                ce.x = 0;
                ce.y = 0;
                ce.width = w->screen->attr_root.width;
                ce.height = w->screen->attr_root.height;
                ce.border_width = 0;
                ce.above = None;
                ce.override_redirect = 0;
                log_warn("we applied all the Configurations");
                if (ev->value_mask & CWStackMode && w->state == STATE_MAPPED)
                {
                        log_warn("applied current");
                        dpy->current = w;
                        set_active_window(dpy->current);
                        log_warn("we are out of this if");
                }
                else if (ev->detail == Below && w == dpy->current)
                {
                        log_warn("applied last window");
                        last_window ();
                }
                log_warn("applied either");

                log_warn("sending event");
                XSendEvent(dpy->display, w->window, False, SubstructureNotifyMask, (XEvent *)&ce);
        }
}
