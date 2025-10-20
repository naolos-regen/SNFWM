#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/logger.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/x11_jobs.h"

void
handle_key (snfwm_screen *s)
{
        XEvent ev;
        KeySym keysym;

        if (!XCheckMaskEvent(dpy->display, KeyPressMask, &ev))
                return;

        keysym = XLookupKeysym((XKeyEvent *) &ev, 0);
        switch (keysym)
        {
                case KEY_XTERM:
                        spawn (TERM_PROG);
                        break;
                case KEY_EMACS:
                        spawn (EMACS_PROG);
                        break;
                case KEY_PREVWINDOW:
                        prev_window();
                        break;
                case KEY_NEXTWINDOW:
                        next_window();
                        break;
                case KEY_TOGGLEBAR:
                        log_warn("no toggle");
                        break;
                case KEY_LASTWINDOW:
                        last_window();
                        break;
                case KEY_DELETE:
                        if (ev.xkey.state & ShiftMask) kill_window();
                        else delete_window();
                        break;
                default:
                        log_warn("not handled");
                        break;
        }
}

void 
keypress(const XEvent *event)
{
        log_info("to implement");
        snfwm_screen *s;
        KeyCode ks;
        unsigned int mod;

        mod = event->xkey.state;
        ks = XLookupKeysym((XKeyEvent *) event, 0);
        s  = find_screen(event->xkey.root);

        if (s && ks == KEY_PREFIX && (mod & MODIFIER_PREFIX))
        {
                handle_key (s);
        }
}
