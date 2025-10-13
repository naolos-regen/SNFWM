#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"

static t_window_list *
find_last_accessed_window (x11_display *dp)
{
        int last_access = 0;
        t_window_list *current;
        t_window_list *most_recent;

        most_recent = dp->head;
        while (most_recent)
        {
                if (most_recent->window->state == STATE_UNMAPPED) break;
                most_recent = most_recent->next;
        }
        if (most_recent == NULL) return (NULL);

        current = dp->head;
        while (current)
        {
                if (current->window->last_access >= last_access 
                    && current != dp->current && current->window->state == STATE_MAPPED)
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
        x11_display *dp;

        dp = x11_display_instance();
        dp->current = find_last_accessed_window(dp);
        set_active_window(dp->current);
}
