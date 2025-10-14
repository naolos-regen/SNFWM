#include "../../include/bar.h"
#include "../../include/x11_data.h"

int
show_bar(snfwm_screen *s)
{
        if (s->bar_raised)
        {
                s->bar_raised = 1;
                XMapWindow(dpy->display, s->bar_window);
                update_window_names(s);
                return (1);
        }
        return (0);
}
