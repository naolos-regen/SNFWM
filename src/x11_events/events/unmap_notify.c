#include "../../../include/x11_events.h"
#include "../../../include/logger.h"
#include "../../../include/bar.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"

void unmap_notify(const XEvent *event)
{
        x11_display *dp;
        snfwm_screen *s;
        t_window_list *w;

        dp = x11_display_instance();
        s = find_screen(event->xunmap.event);
        w = list_find_window(dp->head, event->xunmap.window);

        if (s && w)
        {
                log_debug("both window and screen has been found");
                w->window->state = STATE_UNMAPPED;
                update_window_names (s);
        }
}
