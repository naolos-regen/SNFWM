#include "../../include/linkedlist.h"

static void
swap_nodes(t_window_list *n1, t_window_list *n2)
{
        n1 = n2->next;
        n2->next = n2->prev;
        n2->prev = n1;
}

void
list_reverse(t_window_list **begin_list)
{
        t_window_list    *temp;
        t_window_list    *current;

        current = *begin_list;
        while (current)
        {
                swap_nodes(temp, current);

                if (current->next == NULL)
                {
                        *begin_list = current;
                        break;
                }
                current = current->next;
        }
}
