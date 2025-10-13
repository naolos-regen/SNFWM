#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"

void
goto_window_number (int n)
{
        x11_display *dp;

        dp = x11_display_instance();
        t_window_list *win;

        if ((win = list_at (dp->head, n)) == NULL)
        {
                return;
        }
        dp->current = win;
        set_active_window(dp->current);
}
