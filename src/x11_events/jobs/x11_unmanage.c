#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"

void
unmanage(snfwm_window *w)
{
        list_remove(&dpy->head, w);
}
