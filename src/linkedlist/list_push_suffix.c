#include "../../include/linkedlist.h"


// TODO: test if it even works dummy
static void
list_to_end(t_window_list **list)
{
        while ((*list)->next != NULL)
                (*list) = (*list)->next;
}

int
list_push_suffix(t_window_list **list, snfwm_window *window)
{
        t_window_list *node;

        node = create_elem(window);
        if (NULL == node)
                return (0);
        if (NULL == *list)
        {
                *list = node;
                return (-1);
        }
        t_window_list *idx = *list;
        list_to_end(&idx); 
        idx->next  = node;
        node->prev = idx;
        return (1);
}
