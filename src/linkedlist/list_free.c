#include "../../include/linkedlist.h"
#include <stdlib.h>

void
free_list(snfwm_window **begin_list)
{
        if (!begin_list || !*begin_list)
                return;

        snfwm_window *current = *begin_list;
        snfwm_window *next;

        while (current)
        {
                next = current->next;
                free_node(current);
                current = next;
        }
        *begin_list = NULL;
}
