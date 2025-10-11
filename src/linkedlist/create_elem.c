#include "../../include/linkedlist.h"
#include <stdlib.h>

t_window_list 
*create_elem (snfwm_window *window)
{
        t_window_list *node;

        node = malloc(sizeof(t_window_list));
        if (!node)
        {
                return NULL;
        }
        node->window = window;
        node->next   = NULL;
        node->prev   = NULL;
        return (node);
}
