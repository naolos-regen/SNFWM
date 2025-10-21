#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/logger.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/x11_jobs.h"

void
keypress(const XEvent *event)
{
        snfwm_screen *s;
        unsigned int mod;
        KeySym ks;

        mod = event->xkey.state;
        ks  = XLookupKeysym((XKeyEvent *) event, 0);
        s   = find_screen(event->xkey.root);

        if (!s) return;

        if (mod & MODIFIER_PREFIX_REV)
        {
                switch (ks)
                {
                case KEY_XTERM:
                        spawn(TERM_PROG);
                        break;
                case KEY_EMACS:
                        spawn(EMACS_PROG);
                        break;
                case KEY_PREVWINDOW:
                        prev_window();
                        break;
                case KEY_NEXTWINDOW:
                        next_window();
                        break;
                case KEY_LASTWINDOW:
                        last_window();
                        break;
                case KEY_DELETE:
                        if (mod & ShiftMask) kill_window();
                        else delete_window();
                        break;
                case KEY_TOGGLEBAR:
                        log_warn("toggle bar not implemented");
                        break;
                default:
                        log_warn("Unhandled Mod4+key combo");
                        break;
                }
        }
}
