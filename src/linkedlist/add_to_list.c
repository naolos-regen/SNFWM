#include "../../include/linkedlist.h"
#include "../../include/libx.h"
#include "../../include/x11_data.h"

t_window_list *
add_to_list (snfwm_screen *s, Window w)
{
        t_window_list *nw;
        
        nw = x_malloc(sizeof(t_window_list));
        
        nw->window = x_malloc(sizeof(snfwm_window));
        nw->window->window = w;
        nw->window->screen = s;
        nw->window->last_access = 0;
        nw->window->window_name = x_malloc(x_strlen("Unnamed") + 1);
        x_strcpy(nw->window->window_name, "Unnamed");


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
