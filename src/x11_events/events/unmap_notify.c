#include "../../../include/logger.h"
#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"

void
unmap_notify(const XEvent *event)
{
        snfwm_screen *s;
        t_window_list *w;

        s = find_screen(event->xunmap.event);
        w = list_find_window(dpy->head, event->xunmap.window);

        if (s && w)
        {
                if (w->window)
                {
                        w->state = STATE_UNMAPPED;
                        log_debug("no window update");
                }
        }
}
