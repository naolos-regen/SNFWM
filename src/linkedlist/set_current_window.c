#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"

void
set_current_window (t_window_list *win)
{
        x11_display *dp;

        dp = x11_display_instance();
        dp->current = win;
}
