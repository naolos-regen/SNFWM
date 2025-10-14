#include "../../include/bar.h"
#include "../../include/x11_data.h"

int
hide_bar (snfwm_screen *s)
{
        if (s->bar_raised)
        {
                s->bar_raised = 0;
                XUnmapWindow(dpy->display, s->bar_window);
                return (1);
        }
        return (0);
}
