#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"
#include "../../../include/bar.h"
#include "../../../include/x11_data.h"

#include <X11/Xutil.h>

void
manage (t_window_list *win, snfwm_screen *scr)
{
        if (!update_window_name (win->window)) return;

        XMapWindow (dpy->display, win->window->window);

        log_debug("============================================");
        log_debug("what the hell are the attrs width and height");
        log_warn("The width: %d, & The height: %d", scr->attr_root.width, scr->attr_root.height);
        log_debug("============================================");

        XMoveResizeWindow(dpy->display, win->window->window, 0, 0, scr->attr_root.width, scr->attr_root.height);
        XSelectInput(dpy->display, win->window->window, PropertyChangeMask);
        XAddToSaveSet(dpy->display, win->window->window);
        grab_prefix_key (win->window->window);

        win->window->state = STATE_MAPPED;
}
 
