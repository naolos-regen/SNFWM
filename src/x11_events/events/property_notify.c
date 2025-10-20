#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_data.h"

#include <X11/Xatom.h>

void
property_notify(const XEvent *event)
{
        snfwm_window *win;

        win = list_find_window(dpy->head, event->xproperty.window);

        if (win)
        {
                if (event->xproperty.atom == XA_WM_NAME)
                {
                        log_debug("updating window_name\n");
                }
        }
}
