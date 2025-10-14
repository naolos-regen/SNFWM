#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"
#include "../../../include/logger.h"

void
delete_window ()
{
        XEvent       ev;
        int          st;

        if (dpy->current == NULL) return;

        ev.xclient.type = ClientMessage;
        ev.xclient.window = dpy->current->window->window;
        ev.xclient.message_type = wm_protocols;
        ev.xclient.format = 32;
        ev.xclient.data.l[0] = wm_delete;
        ev.xclient.data.l[1] = CurrentTime;

        st = XSendEvent(dpy->display, dpy->current->window->window, False, 0, &ev);
        if (st == 0)
        {
                log_warn("XSendEvent failed");
        }
}
