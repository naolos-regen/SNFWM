#include "../../../include/x11_events.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_data.h"
#include "../../../include/logger.h"


void
print_out_infos(t_window_list *w)
{
        log_debug("=================================================================");
        log_debug("Window Pointer is equal to:           %p", w);
        log_debug("Window long number is equal to        %ld", w->window);
        log_debug("Window state is equal to              %d", w->state);
        log_debug("=================================================================");
}

void
create_notify (const XEvent *ev)
{
        new_window((XCreateWindowEvent *)ev);
        list_foreach (dpy->head, print_out_infos);             
}
