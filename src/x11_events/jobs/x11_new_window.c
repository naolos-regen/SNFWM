#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void
new_window (const XCreateWindowEvent *e)
{
        log_debug("create event hit");

        snfwm_screen  *s;
        snfwm_window *w;

        if (e->override_redirect)
                return;

        s = find_screen (e->parent);
        w = list_find_window (dpy->head, e->window);
        log_info("=================================================");
        log_info("this is how many windows are now:              %d", dpy->list_size);
        if (s && !w && e->window != s->key_window)
        {
                w = add_to_list (s, e->window);
                w->state = STATE_UNMAPPED;
        }
        log_info("this is how many are after the if statement:   %d", dpy->list_size);
        log_info("=================================================");
}
