#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include <stdlib.h>

void
free_node (snfwm_window *node)
{
        if (!node)
                return;
        if (node->window)
        {
                log_debug("destroying a window");
                XDestroyWindow(dpy->display, node->window);
        }
        free(node);
}
