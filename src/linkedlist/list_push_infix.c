#include "../../include/linkedlist.h"

static t_window_list *
get_node_at(t_window_list *idx, int pos)
{
        int i;

        if (!idx)
                return (NULL);
        i = 1;
        while (idx != NULL && i < pos - 1)
        {
                idx = idx->next;
                i++;
        }
        if (idx == NULL)
                return (NULL);
        return idx;
}

int
list_push_infix(t_window_list **begin_list, snfwm_window *window, int pos)
{
        if (pos < 1)
                return (-1);
        if (pos == 1)
                return list_push_prefix(begin_list, window);


        t_window_list *node;
        t_window_list *idx;
        
        node = create_elem(window);
        idx  = get_node_at(*begin_list, pos);
        
        if (!idx)
                return (-1);
        node->next = idx->next;
        node->prev = idx;
        if (idx->next != NULL)
                idx->next->prev = node;
        idx->next = node;
        return (1);
}
