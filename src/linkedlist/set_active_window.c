#include "../../include/linkedlist.h"
#include "../../include/bar.h"
#include "../../include/x11_data.h"

static int
sanity_check (t_window_list *w)
{
        if (!w)
                return (-1);
        if (!w->window)
                return (-1);
        if (!w->window->screen)
                return (-1);
        return (1);
}

static void
update_window (t_window_list *w, XWindowAttributes *attrs)
{
        if (attrs->map_state == IsViewable && !attrs->override_redirect)
        {
                XSetInputFocus(dpy->display, w->window->window, RevertToPointerRoot, CurrentTime);
                XFlush(dpy->display);
        }
        if (!attrs->override_redirect)
                XRaiseWindow(dpy->display, w->window->window);
        if (w->window->screen->bar_raised)
                update_window_names(w->window->screen);
}

void
set_active_window (t_window_list *w)
{
        static int counter = 1;
        XWindowAttributes attrs;

        sanity_check(w);
        if (!XGetWindowAttributes(dpy->display, w->window->window, &attrs))
                return;
        w->window->last_access = counter;
        update_window(w, &attrs);
}
