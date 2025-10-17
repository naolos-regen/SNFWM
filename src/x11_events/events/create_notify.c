#include "../../../include/x11_events.h"
#include "../../../include/x11_jobs.h"

void
create_notify (const XEvent *ev)
{
        new_window((XCreateWindowEvent *)ev);
}
