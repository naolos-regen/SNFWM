#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

#include <stdlib.h>

void
remove_from_window_list (snfwm_window *w)
{
        if (dpy->head == w) dpy->head = w->next;
        if (dpy->tail == w) dpy->tail = w->prev;

        if (w->prev != NULL) w->prev->next = w->next;
        if (w->next != NULL) w->next->prev = w->prev;

        free(w);
}
