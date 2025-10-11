#include "../../include/linkedlist.h"


// TODO: test if it even works dummy
static t_window_list *
list_to_end(t_window_list *list)
{
        if (!list)
                return (NULL);
        while (list->next != NULL)
                list = list->next;
        return (list);
}

int
list_push_suffix(t_window_list **list, snfwm_window *window)
{
        t_window_list *node;
        t_window_list *idx;

        node = create_elem(window);
        if (NULL == node)
                return (0);
        if (NULL == *list)
        {
                *list = node;
                return (-1);
        }
        idx = list_to_end(*list);
        idx->next  = node;
        node->prev = idx;
        return (1);
}
