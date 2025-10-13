#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/logger.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/bar.h"
#include "../../../include/x11_jobs.h"

static void
handle_key (snfwm_screen *s)
{
        x11_display *dp;
        int revert;
        Window fwin;
        XEvent ev;
        
        dp = x11_display_instance();

        XGetInputFocus(dp->display, &fwin, &revert);
        XSetInputFocus(dp->display, s->key_window, RevertToPointerRoot, CurrentTime);
        XMaskEvent(dp->display, KeyPressMask, &ev);
        XSetInputFocus(dp->display, fwin, revert, CurrentTime);

        if (XLookupKeysym((XKeyEvent *) &ev, 0) == KEY_PREFIX && !ev.xkey.state)
        {
                ev.xkey.window = fwin;
                ev.xkey.state = MODIFIER_PREFIX;
                XSendEvent (dp->display, fwin, False, KeyPressMask, &ev);
                XSync(dp->display, False);
                return;
        }
        if (XLookupKeysym((XKeyEvent *) &ev, 0) >= '0' 
            && XLookupKeysym((XKeyEvent *) &ev, 0) <= '9')
        {
                goto_window_number (XLookupKeysym((XKeyEvent *) &ev, 0) - '0');
                return;
        }

        switch (XLookupKeysym((XKeyEvent *) &ev, 0))
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
                        toggle_bar (s);
                        break;
                case KEY_LASTWINDOW:
                        last_window();
                        break;
                case KEY_DELETE:
                        //if (ev.xkey.state & ShiftMask) kill_window();
                        //else delete_window();
                        break;
                default:
                        log_warn("not handled");
                        break;
        }
}

void keypress(const XEvent *event)
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
