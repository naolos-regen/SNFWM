#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"

void
unmanage(snfwm_window *w)
{
        if (NULL == w)
        {
                return;
        }

        if (dpy->current == w)
        {
                dpy->current = NULL;
        }

        remove_from_window_list(w);
}
