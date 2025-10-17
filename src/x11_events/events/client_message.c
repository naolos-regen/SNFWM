#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/x11_data.h"

void
client_message(const XEvent *event)
{
        char *msg = XGetAtomName(dpy->display, event->xclient.message_type);
        if (!msg)
                return;
        log_info("Window: %lu", event->xclient.window);
        log_info("recieved a message : %s", msg);
        log_info("Format: %d\n", event->xclient.format);

        for (int i = 0 ; i < 5; i++)
        {
                log_info("Data[%d] %ld (0x%1x)", i, event->xclient.data.l[i], event->xclient.data.l[i]);
        }

        XFree(msg);
}
