#include "../../include/linkedlist.h"
#include "../../include/libx.h"
#include "../../include/x11_data.h"

static snfwm_window *
create_snfwm_window (snfwm_screen *s, Window w)
{
        snfwm_window *win;

        win = x_malloc(sizeof(snfwm_window));
        
        win->window = w;
        win->screen = s;
        win->last_access = 0;
        win->window_name = x_malloc(x_strlen("Unnamed") + 1);
        x_strcpy(win->window_name, "Unnamed");
        
        return (win);
}

t_window_list *
add_to_list (snfwm_screen *s, Window w)
{
        t_window_list *nw;

        nw = x_malloc(sizeof(t_window_list));
        nw->window = create_snfwm_window(s, w);
        if (NULL == dpy->head)
        {
                dpy->head = nw;
                dpy->tail = nw;
                nw->next = NULL;
                return (nw);
        }
        nw->next = dpy->head;
        dpy->head->prev = nw;
        dpy->head = nw;
        return (nw);
}
