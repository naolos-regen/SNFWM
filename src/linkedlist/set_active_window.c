#include "../../include/linkedlist.h"
#include "../../include/logger.h"
#include "../../include/bar.h"
#include "../../include/x11_data.h"

void
set_active_window (t_window_list *w)
{
        static int counter = 1;

        if (!w)
        {
                log_error("set_active_window: w is NULL");
                return;
        }

        if (!w->window)
        {
                log_error("set_active_window: w->window is NULL");
                return;
        }
        XWindowAttributes attrs;
        
        if (!XGetWindowAttributes(dpy->display, w->window->window, &attrs))
        {
                log_error("set_active_window: Failed to get attributes for window: %lu", w->window->window);
                return;
        }

        if (!w->window->screen)
        {
                log_error("set_active_window: w->window->screen is NULL");
                return;
        }

        counter++;
        w->window->last_access = counter;

        log_debug("Setting input focus to window: %lu", w->window->window);

        if (w->window->screen->bar_raised)
                update_window_names(w->window->screen);

        if (attrs.map_state == IsViewable && !attrs.override_redirect)
        {
                XSetInputFocus(dpy->display, w->window->window, RevertToPointerRoot, CurrentTime);
                XFlush(dpy->display);
        }
        if (!attrs.override_redirect)
        {
                XRaiseWindow(dpy->display, w->window->window);
        }
        if (w->window->screen->bar_raised)
                update_window_names(w->window->screen);
}
