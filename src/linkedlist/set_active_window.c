#include "../../include/linkedlist.h"
#include "../../include/x11_data.h"

static int
sanity_check (t_window_list *w)
{
        if (!w)
                return (-1);
        if (!w->screen)
                return (-1);
        return (1);
}

static void
update_window (t_window_list *w, XWindowAttributes *attrs)
{
        if (attrs->map_state == IsViewable && !attrs->override_redirect)
        {
                XSetInputFocus(dpy->display, w->window, RevertToPointerRoot, CurrentTime);
                XFlush(dpy->display);
        }
        if (!attrs->override_redirect)
                XRaiseWindow(dpy->display, w->window);
}

void
set_active_window (t_window_list *w)
{
        static int counter = 1;
        XWindowAttributes attrs;

        sanity_check(w);
        if (!XGetWindowAttributes(dpy->display, w->window, &attrs))
                return;
        w->last_access = counter;
        update_window(w, &attrs);
}
