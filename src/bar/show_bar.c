#include "../../include/x11_helpers.h"
#include "../../include/bar.h"

int
show_bar(snfwm_screen *s)
{
        if (s->bar_raised)
        {
                x11_display *dpy = x11_display_instance();
                s->bar_raised = 1;
                XMapWindow(dpy->display, s->bar_window);
                update_window_names(s);
                
                return (1);
        }
        return (0);
}
