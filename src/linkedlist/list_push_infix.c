#include "../../include/linkedlist.h"

static int
skip_till_pos(t_window_list **idx, int pos)
{
        int i;

        i = 1;
        while ((*idx) != NULL && i < pos - 1)
        {
                (*idx) = (*idx)->next;
                i++;
        }
        if ((*idx) == NULL)
                return (-1);
        return (i);
}

// TODO: this might not work (?)
int
list_push_infix(t_window_list **begin_list, snfwm_window *window, int pos)
{
        if (pos < 1)
                return (-1);
        if (pos == 1)
                return list_push_prefix(begin_list, window);


        t_window_list *node;
        t_window_list *idx;
        int insert_pos;
        
        node = create_elem(window);
        idx  = *begin_list;
        insert_pos = skip_till_pos(&idx, pos);
        if (!insert_pos)
                return (-1);
        node->next = idx->next;
        node->prev = idx;
        if (idx->next != NULL)
                idx->next->prev = node;
        idx->next = node;
        return (2);
}
