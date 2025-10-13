#include "../../../include/x11_events.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/linkedlist.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void map_request(const XEvent *event)
{
        log_info("I'm trying to map");
        snfwm_screen *scr;
        t_window_list *win;
        x11_display  *dpy;

        dpy = x11_display_instance ();
        scr = find_screen (event->xmap.event);
        win = list_find_window (dpy->head, event->xmap.window);
        

        if (scr && win)
        {
                switch (win->window->state)
                {
                case STATE_UNMAPPED:
                        manage(win->window, scr);
                        break;
                case STATE_MAPPED:
                        XMapRaised(dpy->display, win->window->window);
                        dpy->current = dpy->head;
                        set_active_window(dpy->head);
                        break;
                }
        }
}
