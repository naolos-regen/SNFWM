#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"

void
unmanage(snfwm_window *w)
{
        x11_display *dp = x11_display_instance();
        list_remove(&dp->head, w);
}
