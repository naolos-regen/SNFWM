#include "../../include/linkedlist.h"

void
list_foreach(snfwm_window *begin_list, void (*f)(snfwm_window *))
{
        snfwm_window *p;

        p = begin_list;
        while (p != NULL)
        {
                if (p->window)
                        f(p);
                p = p->next;
        }
}
