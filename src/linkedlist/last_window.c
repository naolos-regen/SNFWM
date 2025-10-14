#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

static t_window_list *
find_last_accessed_window ()
{
        int last_access = 0;
        t_window_list *current;
        t_window_list *most_recent;

        most_recent = dpy->head;
        while (most_recent)
        {
                if (most_recent->window->state == STATE_UNMAPPED) break;
                most_recent = most_recent->next;
        }
        if (most_recent == NULL) return (NULL);

        current = dpy->head;
        while (current)
        {
                if (current->window->last_access >= last_access 
                    && current != dpy->current && current->window->state == STATE_MAPPED)
                {
                        most_recent = current;
                        last_access = current->window->last_access;
                }
                current = current->next;
        }
        return (most_recent);
}


void
last_window (void)
{
        dpy->current = find_last_accessed_window();
        set_active_window(dpy->current);
}
