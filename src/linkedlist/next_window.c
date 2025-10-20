#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

void
next_window()
{
        if (dpy->current != NULL)
        {
                dpy->current = dpy->current->next;
                if (dpy->current == NULL)
                {
                        dpy->current = dpy->head;
                }
                if (dpy->current->state == STATE_UNMAPPED) next_window ();
                set_active_window (dpy->current);
        }
}
