#include "../../include/linkedlist.h"
#include "../../include/libx.h"
#include "../../include/x11_data.h"

t_window_list *
add_to_list (snfwm_screen *s, Window w)
{
        t_window_list *nw;
        nw = x_malloc(sizeof(t_window_list));
        
        nw->window = w;
        nw->window = w;
        nw->screen = s;
        nw->last_access = 0;
        
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
        dpy->list_size = dpy->list_size + 1;
        return (nw);
}
