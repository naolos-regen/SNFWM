#include "../../include/linkedlist.h"

void 
list_reverse(snfwm_window **begin_list)
{
    snfwm_window *temp;
    snfwm_window *current;

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

