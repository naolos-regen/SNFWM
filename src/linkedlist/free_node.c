#include "../../include/linkedlist.h"
#include <stdlib.h>

void
free_node (t_window_list *node)
{
        if (!node)
                return;
        if (node->window)
                free_window(node->window);
        free(node);
}
