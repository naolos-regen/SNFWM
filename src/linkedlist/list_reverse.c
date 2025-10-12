#include "../../include/linkedlist.h"

void 
list_reverse(t_window_list **begin_list)
{
    t_window_list *temp;
    t_window_list *current;

    if (!begin_list || !*begin_list)
        return;

    current = *begin_list;

    while (current)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        if (!temp)
        {
            *begin_list = current;
            break;
        }

        current = temp;
    }
}

