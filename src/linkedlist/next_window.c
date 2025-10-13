#include "../../include/linkedlist.h"
#include "../../include/x11_helpers.h"

void
next_window()
{
        x11_display *dp;

        dp = x11_display_instance();
        if (dp->current != NULL)
        {
                dp->current = dp->current->next;
                if (dp->current == NULL)
                {
                        dp->current = dp->head;
                }
                if (dp->current->window->state == STATE_UNMAPPED) next_window ();
                set_active_window (dp->current);
        }
}
