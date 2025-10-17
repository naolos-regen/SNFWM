#include "../../include/x11_helpers.h"
#include "../../include/x11_events.h"
#include "../../include/logger.h"

static char *event_name[] = {
        "", "", "KeyPress", "KeyRelease", "ButtonPress", "ButtonRelease",
        "MotionNotify", "EnterNotify", "LeaveNotify", "FocusIn", "FocusOut",
        "KeymapNotify", "Expose", "GraphicsExpose", "NoExpose", "VisibilityNotify",
        "CreateNotify", "DestroyNotify", "UnmapNotify", "MapNotify", "MapRequest",
        "ReparentNotify", "ConfigureNotify", "ConfigureRequest", "GravityNotify"
};

void 
x11_main_loop (void)
{
        XEvent ev;
        while(1)
        {
                XNextEvent(dpy->display, &ev);

                if (handler[ev.type]){
                        log_debug("Event type: %s (%d)", event_name[ev.type], ev.type);
                        handler[ev.type](&ev);
                }
        }
}
