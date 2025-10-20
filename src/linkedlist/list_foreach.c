#include "../../include/linkedlist.h"

void
list_foreach(t_window_list *begin_list, void (*f)(t_window_list *))
{
        t_window_list *p;

        p = begin_list;
        while (p != NULL)
        {
                if (p->window)
                        f(p);
                p = p->next;
        }
}
