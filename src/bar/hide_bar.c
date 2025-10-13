#include "../../include/bar.h"
#include "../../include/x11_helpers.h"

int
hide_bar (t_window_list *w)
{
        if (w->window->screen->bar_raised)
        {
                x11_display *dpy = x11_display_instance();
                w->window->screen->bar_raised = 0;
                XUnmapWindow(dpy->display, w->window->screen->bar_window);
                return (1);
        }
        return (0);
}
