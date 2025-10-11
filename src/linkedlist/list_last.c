#include "../../include/linkedlist.h"

t_window_list 
*list_last (t_window_list *begin_list)
{
        t_window_list *node;

        node = begin_list;
        while (node != NULL)
                node = node->next;
        return (node);
}
