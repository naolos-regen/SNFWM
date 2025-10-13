#include "../../include/x11_helpers.h"
#include "../../include/bar.h"

int
show_bar(t_window_list *w)
{
        if (w->window->screen->bar_raised)
        {
                x11_display *dpy = x11_display_instance();
                w->window->screen->bar_raised = 1;
                XMapWindow(dpy->display, w->window->screen->bar_window);
                update_window_names(w);
                
                return (1);
        }
        return (0);
}
