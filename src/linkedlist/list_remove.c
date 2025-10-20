#include "../../include/linkedlist.h"
#include <stdlib.h>

static int
remove_node(t_window_list **begin_list, t_window_list *remove)
{
        if (remove->prev != NULL)
                remove->prev->next = remove->next;
        else
                *begin_list = remove->next;
        if (remove->next != NULL)
                remove->next->prev = remove->prev;
        free_node(remove);
        return (0);
}

int
list_remove(t_window_list **begin_list, t_window_list *w)
{
        t_window_list *current;
        t_window_list *next;

        if (!begin_list || !*begin_list || !w)
                return (-1);
        
        current = *begin_list;
        while (current)
        {
                next = current->next;
                if (comparator(w, current) == 0)
                       remove_node(begin_list, current);
                current = next;
        }
        return (-1);
}
