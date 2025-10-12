#include "../../include/linkedlist.h"

int
list_push_prefix(t_window_list **list, snfwm_window *window)
{
        t_window_list *node;
        
        node = create_elem(window);
        if (NULL == node)
                return (0);
        if (NULL == *list)
        {
                *list = node;
                return (1);
        }
        node->next    = *list;
        (*list)->prev = node;
        *list = node;
        return (-1);
}
