#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
prev_window()
{
        if (dpy->current != NULL)
        {
                set_current_window(dpy->current->prev);
                if (dpy->current == NULL)
                {
                        dpy->current = dpy->tail;
                }
                if (dpy->current->window->state == STATE_UNMAPPED) prev_window();
                set_active_window(dpy->current);
        }
}
