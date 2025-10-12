#include "../../include/linkedlist.h"

static int
sanity_check(t_window_list **begin_list, t_window_list *remove)
{
        if (!begin_list || !*begin_list || !remove)
                return (-1);
        return (1);
}

static int
remove_node(t_window_list **begin_list, t_window_list *remove)
{
        if (sanity_check(begin_list, remove) == -1)
                return (-1);
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
list_remove(t_window_list **begin_list, snfwm_window *data)
{
        t_window_list *current;

        if (!begin_list || !*begin_list || !data)
                return (-1);
        
        current = *begin_list;
        while (current)
        {
                if (comparator(data, current->window) == 0)
                       remove_node(begin_list, current);
                current = current->next;
        }
        return (-1);
}
