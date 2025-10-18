#include "../../../include/x11_data.h"
#include "../../../include/x11_events.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

static void
state_check (t_window_list *w, snfwm_screen *s)
{
        switch (w->window->state)
        {
                case STATE_UNMAPPED:
                        manage(w, s);
                        break;
                case STATE_MAPPED:
                        XMapRaised(dpy->display, w->window->window);
                        dpy->current = w;
                        set_active_window(dpy->current);
                        break;
                default:
                        XMapWindow(dpy->display, w->window->window);
        }
}

void
map_request (const XEvent *event)
{
        log_info("Map Request Received");
        snfwm_screen *scr; 
        t_window_list *win;

        scr = find_screen(event->xmap.event);
        win = list_find_window(dpy->head, event->xmap.window);
        
        if (!scr || !win)
        {
                log_error("No screen found for this window");
                XMapWindow(dpy->display, event->xmap.window);
                return;
        }
        
        state_check(win, scr);
}
