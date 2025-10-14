#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"
#include "../../../include/logger.h"

void
scan_windows(snfwm_screen *s)
{
        XWindowAttributes attr;
        unsigned int i, nwins;
        Window dw1, dw2, *wins;

        XQueryTree(dpy->display, dpy->root, &dw1, &dw2, &wins, &nwins);
        i = 0;
        log_warn("%d length of wins", nwins);

        for (;i < nwins; i++)
        {
                XGetWindowAttributes(dpy->display, wins[i], &attr);
                if (wins[i] == s->bar_window || wins[i] == s->key_window) continue;
                
                snfwm_window win = { .window = wins[i] };
                list_push_prefix(&dpy->head, &win);
        }
        XFree((void *) wins);
}

