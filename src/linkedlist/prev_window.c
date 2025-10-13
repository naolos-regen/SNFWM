#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"

void
prev_window()
{
        x11_display *dp;

        dp = x11_display_instance();
        
        if (dp->current != NULL)
        {
                set_current_window(dp->current->prev);
                if (dp->current == NULL)
                {
                        dp->current = dp->tail;
                }
                if (dp->current->window->state == STATE_UNMAPPED) prev_window();
                set_active_window(dp->current);
        }

}
