#include "../../include/linkedlist.h"

t_window_list 
*list_at (t_window_list *begin_list, unsigned int n)
{
        if (!begin_list)
                return NULL;
        
        unsigned int index;
        t_window_list *p;
        
        index = 0;
        p = begin_list;
        while(p != NULL && index < n)
        {
                p = p->next;
                index = index + 1;
        }
        return (p);
}
