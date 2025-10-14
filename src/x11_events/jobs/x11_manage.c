#include "../../../include/x11_jobs.h"
#include "../../../include/x11_config.h"
#include "../../../include/logger.h"
#include "../../../include/x11_data.h"

#include <X11/Xutil.h>
#include <stdlib.h>
#include <string.h>

static void
grab_prefix_key (Display *dpy, Window w)
{
        XGrabKey(dpy, XKeysymToKeycode(dpy, KEY_PREFIX), MODIFIER_PREFIX, w, True, GrabModeAsync, GrabModeAsync);
}

static void
x11_funcs_manage(snfwm_window *w, snfwm_screen *s)
{
        XMapWindow(dpy->display, w->window);
        XMoveResizeWindow(dpy->display, w->window, 0, 0, s->attr_root.width, s->attr_root.height);
        XSelectInput(dpy->display, w->window, PropertyChangeMask);
        XAddToSaveSet(dpy->display, w->window);
}

static void
allocate_char (XClassHint hint, snfwm_window *win)
{
        if (win->window_name != NULL)
                free(win->window_name);
        if (NULL == (win->window_name = malloc(strlen(hint.res_name) + 1)))
        {
                log_warn("out of mem");
                exit_signal = 1;
        }
        strcpy(win->window_name, hint.res_name);
}


void
manage (snfwm_window *win, snfwm_screen *scr)
{
        log_info("I'm in manage");
        XClassHint hint;
        
        win->state = STATE_MAPPED;
        x11_funcs_manage(win, scr);
        grab_prefix_key(dpy->display, win->window);
        if (!XGetClassHint (dpy->display, win->window, &hint))
        {
                log_warn("snfwm : I can't get the Classhints, I don't know what to do!");
                exit_signal = 1;
        }
        allocate_char(hint, win);
        XFree(hint.res_name);
        XFree(hint.res_class);
}
