#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"

void
kill_window (void)
{
        if (dpy->current == NULL) 
                return;
        if (dpy->current->window == dpy->root) 
                return;
        XKillClient(dpy->display, dpy->current->window);
}
