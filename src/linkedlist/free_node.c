#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"
#include <stdlib.h>

void
free_node (snfwm_window *node)
{
        if (!node)
                return;
        if (node->window)
                XDestroyWindow(dpy->display, node->window);
        free(node);
}
