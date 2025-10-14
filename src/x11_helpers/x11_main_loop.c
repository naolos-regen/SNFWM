#include "../../include/x11_helpers.h"
#include "../../include/x11_events.h"

void 
x11_main_loop (void)
{
        XEvent ev;
        while(1)
        {
                XNextEvent(dpy->display, &ev);
                if (handler[ev.type]) 
                        handler[ev.type](&ev);
        }
}
