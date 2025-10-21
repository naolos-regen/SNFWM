#include "../../../include/x11_events.h"
#include "../../../include/linkedlist.h"
#include "../../../include/logger.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/x11_jobs.h"

void
handle_key (snfwm_screen *s)
{
        int revert;
        Window fwin;
        XEvent ev;

        XGetInputFocus(dpy->display, &fwin, &revert);
        XSetInputFocus(dpy->display, s->key_window, RevertToPointerRoot, CurrentTime);
        XMaskEvent(dpy->display, KeyPressMask, &ev);
        XSetInputFocus(dpy->display, fwin, revert, CurrentTime);
        
        switch (XLookupKeysym((XKeyEvent *)&ev, 0))
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
        unsigned int mod;

        mod = event->xkey.state;
        s   = find_screen(event->xkey.root);

        if (!s || !(mod & MODIFIER_PREFIX)) return;
        
        handle_key (s);
}
