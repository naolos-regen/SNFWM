#include "../../../include/x11_jobs.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"

void 
new_window (t_window_list *begin_list, const XCreateWindowEvent *e)
{
        snfwm_window *win;
        snfwm_screen *scr;

        if (e->override_redirect)
                return;
        
        win = list_find_window(begin_list, e->window)->window;
        scr = find_screen(e->parent);

        if (scr && !win && e->window != scr->key_window && e->window != scr->bar_window)
        {
                win->state = STATE_UNMAPPED;
        }
}
