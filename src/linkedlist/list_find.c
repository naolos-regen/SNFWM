#include "../../include/linkedlist.h"

t_window_list *
list_find(t_window_list *begin_list, snfwm_window *data)
{
        t_window_list *p;
        if (NULL == begin_list || NULL == data)
                return (NULL);

        p = begin_list;
        while (NULL != p)
        {
                if (comparator(data, p->window) == 0)
                        return (p);
                p = p->next;
        }
        return (NULL);
}

