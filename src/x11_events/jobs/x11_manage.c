#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"
#include "../../../include/x11_data.h"

#include <X11/Xutil.h>

void
manage (snfwm_window *win, snfwm_screen *scr)
{
        XMapWindow (dpy->display, win->window);

        log_debug("============================================");
        log_debug("what the hell are the attrs width and height");
        log_debug("The width: %d, & The height: %d", scr->attr_root.width, scr->attr_root.height);
        log_debug("the size of the list is: %d", dpy->list_size);
        log_debug("============================================");
        
        XMoveResizeWindow(dpy->display, win->window, 0, 0, scr->attr_root.width, scr->attr_root.height);
        XSelectInput(dpy->display, win->window, PropertyChangeMask);
        XAddToSaveSet(dpy->display, win->window);
        grab_prefix_key (win->window);

        win->state = STATE_MAPPED;
}
 
