#include "../../../include/linkedlist.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_data.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

void
new_window (const XCreateWindowEvent *e)
{
        if (e->override_redirect)
                return;

        snfwm_screen *scr = find_screen(e->parent);
        if (!scr)
        {
                log_error("No screen found for parent window %lu", e->parent);
                return;
        }

        t_window_list *existing_win = list_find_window(dpy->head, e->window);
        if (existing_win)
        {
                log_debug("Window %lu already in list", e->window);
                return;
        }

        if (e->window == scr->key_window || e->window == scr->bar_window)
        {
                log_debug("Skipping special window %lu", e->window);
                return;
        }

        t_window_list *new_win = add_to_list(scr, e->window);
        if (new_win)
        {
                log_info("Added new window %lu to list", e->window);
                if (new_win->window)
                {
                        new_win->window->state = STATE_UNMAPPED;
                }
        }
        else
        {
                log_error("Failed to add window %lu to list", e->window);
        }
}
