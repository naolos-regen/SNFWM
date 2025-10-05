#include "../../include/x11_helpers.h"
#include "../../include/logger.h"

void x11_main_loop(x11_display *dp)
{
        XEvent ev;
        while(1)
        {
                XNextEvent(dp->display, &ev);
                switch (ev.type)
                {
                        case KeyPress:
                                log_info("key has been pressed");
                                break;
                        case MotionNotify:
                                log_info("motion");
                                break;
                        default:
                                log_warn("not handled");
                                break;
                }
        }
}
