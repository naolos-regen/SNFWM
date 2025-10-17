#include "../../../include/x11_data.h"
#include "../../../include/x11_events.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void
map_request(const XEvent *event)
{
        log_info("Map Request Received");

        log_info("Window ID: %lu", event->xmap.window);
        log_info("Event Window: %lu", event->xmap.event);

        snfwm_screen *scr = find_screen(event->xmap.event);
        t_window_list *win = list_find_window(dpy->head, event->xmap.window);

        if (!scr)
        {
                log_error("No screen found for this window");
                XMapWindow(dpy->display, event->xmap.window);
                return;
        }

        if (!win)
        {
                log_warn("Window not in managed list, force mapping");
                XMapWindow(dpy->display, event->xmap.window);
                return;
        }

        // Detailed state logging
        log_info("Current Window State: %d", win->window->state);

        switch (win->window->state)
        {
        case STATE_UNMAPPED:
                log_info("Managing unmapped window");
                manage(win, scr);
                break;
        case STATE_MAPPED:
                log_info("Raising mapped window");
                XMapRaised(dpy->display, win->window->window);
                dpy->current = win;
                set_active_window(dpy->current);
                break;
        default:
                log_warn("Unexpected window state");
                XMapWindow(dpy->display, event->xmap.window);
        }
}
