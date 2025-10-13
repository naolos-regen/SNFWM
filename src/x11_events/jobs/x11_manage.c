#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/logger.h"

#include <X11/Xutil.h>
#include <stdlib.h>
#include <string.h>

static void
grab_prefix_key (Display *dpy, Window w)
{
        XGrabKey(dpy, XKeysymToKeycode(dpy, KEY_PREFIX), MODIFIER_PREFIX, w, True, GrabModeAsync, GrabModeAsync);
}

void
manage (snfwm_window *win, snfwm_screen *scr)
{
        log_info("I'm in manage");
        XClassHint hint;
        x11_display *dpy = x11_display_instance();
        XMapWindow(dpy->display, win->window);
        XMoveResizeWindow(dpy->display, win->window, 0, 0, scr->attr_root.width, scr->attr_root.height);
        XSelectInput(dpy->display, win->window, PropertyChangeMask);
        XAddToSaveSet(dpy->display, win->window);
        grab_prefix_key(dpy->display, win->window);

        win->state = STATE_MAPPED;

        if (!XGetClassHint (dpy->display, win->window, &hint))
        {
                log_warn("snfwm : I can't get the Classhints, I don't know what to do!");
                exit(EXIT_FAILURE);
        }
        free(win->window_name);
        if ((win->window_name = malloc (strlen(hint.res_name) + 1)) == NULL)
        {
                log_warn("out of mem");
                exit (EXIT_FAILURE);
        }
        strcpy(win->window_name, hint.res_name);

        XFree(hint.res_name);
        XFree(hint.res_class);
}
