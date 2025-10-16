#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"

void 
new_window (const XCreateWindowEvent *e)
{
        t_window_list *win;
        snfwm_screen *scr;

        if (e->override_redirect)
                return;
        
        win = list_find_window(dpy->head, e->window);
        scr = find_screen(e->parent);

        if (scr && !win && e->window != scr->key_window && e->window != scr->bar_window)
        {
                win = add_to_list(scr, win->window->window);
                win->window->state = STATE_UNMAPPED;
        }
}
