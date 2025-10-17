#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/bar.h"
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
                log_debug("both window and screen has been found");
                if (w->window)
                {
                        w->window->state = STATE_UNMAPPED;
                        update_window_names (s);
                }
                else 
                        log_warn("null_pointer");
        }
        log_debug("it's out?");
}
