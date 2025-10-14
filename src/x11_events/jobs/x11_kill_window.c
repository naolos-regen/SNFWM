#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"

void
kill_window ()
{
        if (dpy->current == NULL) return;
        XKillClient(dpy->display, dpy->current->window->window);
}
