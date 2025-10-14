#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"

void 
new_window (const XCreateWindowEvent *e)
{
        snfwm_window *win;
        snfwm_screen *scr;

        if (e->override_redirect)
                return;
        
        win = list_find_window(dpy->head, e->window)->window;
        scr = find_screen(e->parent);

        if (scr && !win && e->window != scr->key_window && e->window != scr->bar_window)
        {
                win->state = STATE_UNMAPPED;
        }
}
