#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void
unmanage(snfwm_window *w)
{
        if (NULL == w)
        {
                return;
        }
        
        snfwm_window *found = list_find_window(dpy->head, w->window);
        if (!found)
                return;

        if (dpy->current == w)
                dpy->current = NULL;
        
        log_info("unamaging window");
        remove_from_window_list(w);
}
