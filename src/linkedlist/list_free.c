#include "../../include/linkedlist.h"
#include <stdlib.h>

void
list_free(t_window_list **begin_list)
{
        if (!begin_list || !*begin_list)
                return;

        t_window_list *current = *begin_list;
        t_window_list *next;

        while (current)
        {
                next = current->next;
                free_node(current);
                current = next;
        }
        *begin_list = NULL;
}
