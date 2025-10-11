#include "../../include/linkedlist.h"

int
list_size(t_window_list *begin_list)
{
        t_window_list *p;
        int index;

        if (!begin_list)
                return (0);
        p = begin_list;
        index = 0;
        while (p != NULL)
        {
                index++;
                p = p->next;
        }
        return (index);
}
