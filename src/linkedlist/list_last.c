#include "../../include/linkedlist.h"

snfwm_window 
*list_last (snfwm_window *begin_list)
{
        snfwm_window *node;

        node = begin_list;
        while (node != NULL)
                node = node->next;
        return (node);
}
