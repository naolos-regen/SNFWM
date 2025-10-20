#include "../../include/linkedlist.h"

snfwm_window
*list_find_window(snfwm_window *begin_list, Window window)
{
        snfwm_window *current;
        
        current = begin_list;
        while (current != NULL)
        {
                if (current != NULL && current->window == window)
                        return (current);       
                current = current->next;
        }
        return NULL;
}
