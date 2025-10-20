#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"
#include "../../../include/logger.h"

void
scan_windows(snfwm_screen *s)
{
        t_window_list *win;
        XWindowAttributes attr;
        unsigned int i, nwins;
        Window dw1, dw2, *wins;

        XQueryTree(dpy->display, dpy->root, &dw1, &dw2, &wins, &nwins);
        log_warn("%d length of wins", nwins);

        i = 0;
        for (;i < nwins; i++)
        {
                XGetWindowAttributes(dpy->display, wins[i], &attr);
                if (wins[i] == s->key_window) continue;
                win = add_to_list(s, wins[i]);
                manage(win, s);
        }
        XFree((void *) wins);
}

