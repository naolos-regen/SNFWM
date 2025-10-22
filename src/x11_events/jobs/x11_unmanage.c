#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"

void
unmanage(snfwm_window *w)
{
        remove_from_window_list(w);
}
