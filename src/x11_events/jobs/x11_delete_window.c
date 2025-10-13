#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/logger.h"

void
delete_window ()
{
        x11_display *dp;
        XEvent       ev;
        int          st;

        dp = x11_display_instance();

        if (dp->current == NULL) return;

        ev.xclient.type = ClientMessage;
        ev.xclient.window = dp->current->window->window;
        ev.xclient.message_type = wm_protocols;
        ev.xclient.format = 32;
        ev.xclient.data.l[0] = wm_delete;
        ev.xclient.data.l[1] = CurrentTime;

        st = XSendEvent(dp->display, dp->current->window->window, False, 0, &ev);
        if (st == 0)
        {
                log_warn("XSendEvent failed");
        }
}
