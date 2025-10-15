#include "../../include/linkedlist.h"
#include "../../include/libx.h"
#include <stdlib.h>

t_window_list 
*create_elem (snfwm_window *window)
{
        if (!window)
                return (NULL);
        t_window_list *node;

        node = x_malloc(sizeof(t_window_list));
        
        node->window = window;
        node->window->last_access = 0;
        node->next   = NULL;
        node->prev   = NULL;
        return (node);
}
