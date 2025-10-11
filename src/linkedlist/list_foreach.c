#include "../../include/linkedlist.h"

void
list_foreach(t_window_list *begin_list, void (*f)(snfwm_window *))
{
        t_window_list *p;

        p = begin_list;
        while (p != NULL)
        {
                if (p->window)
                        f(p->window);
                p = p->next;
        }
}
