#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void
scan_windows(snfwm_screen *s)
{
        x11_display *dp;
        XWindowAttributes attr;
        unsigned int i, nwins;
        Window dw1, dw2, *wins;

        dp = x11_display_instance();
        XQueryTree(dp->display, dp->root, &dw1, &dw2, &wins, &nwins);
        i = 0;
        log_warn("%d length of wins", nwins);

        for (;i < nwins; i++)
        {
                log_debug("we are within a loop in snfwm_screen %d", i);
                
                XGetWindowAttributes(dp->display, wins[i], &attr);
                if (wins[i] == s->bar_window || wins[i] == s->key_window) continue;
                
                snfwm_window win = {
                        .window = wins[i],
                };
                list_push_prefix(&dp->head, &win);
        }
        XFree((void *) wins);
}

