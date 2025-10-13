#include "../../../include/x11_helpers.h"
#include "../../../include/x11_config.h"
#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"

static void
grab_key (x11_display *dp, snfwm_screen *s, char key)
{
        XGrabKey(dp->display, XKeysymToKeycode(dp->display, key), AnyModifier, s->key_window, True, GrabModeAsync, GrabModeAsync);
}

void
grab_keys (snfwm_screen *s)
{
        x11_display *dp;
        int i;

        log_warn("ello");

        dp = x11_display_instance();
        i = '0';
        while (i < '9')
        {
                grab_key(dp, s, (char) i);
                XGrabKey(dp->display, XKeysymToKeycode(dp->display, i), AnyModifier, s->key_window, True, GrabModeAsync, GrabModeAsync);
                i++;
                log_warn("%d HO", i);
        }
        grab_key(dp, s, KEY_XTERM);
        grab_key(dp, s, KEY_EMACS);
        grab_key(dp, s, KEY_PREVWINDOW);
        grab_key(dp, s, KEY_NEXTWINDOW);
        grab_key(dp, s, KEY_TOGGLEBAR);
        grab_key(dp, s, KEY_LASTWINDOW);
        grab_key(dp, s, KEY_DELETE);
        grab_key(dp, s, KEY_PREFIX);
        log_warn("we done here innit");
}
