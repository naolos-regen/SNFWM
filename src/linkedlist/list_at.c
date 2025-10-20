#include "../../include/linkedlist.h"

snfwm_window 
*list_at (snfwm_window *begin_list, unsigned int n)
{
        if (!begin_list)
                return NULL;
        
        unsigned int index;
        snfwm_window *p;
        
        index = 0;
        p = begin_list;
        while(p != NULL && index < n)
        {
                p = p->next;
                index = index + 1;
        }
        return (p);
}
