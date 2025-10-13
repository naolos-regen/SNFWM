#include "../../include/linkedlist.h"

t_window_list *
list_find_window(t_window_list *begin_list, Window window)
{
        t_window_list *current;

        current = begin_list;
        while (current)
        {
                if (current->window->window == window) 
                        return (current);
                current = current->next;
        }
        return (NULL);
}
