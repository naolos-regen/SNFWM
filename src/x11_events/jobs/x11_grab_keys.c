#include "../../../include/x11_config.h"
#include "../../../include/x11_data.h"
#include "../../../include/x11_jobs.h"

static void
grab_key (snfwm_screen *s, char key, unsigned int modifier)
{
        KeyCode kc = XKeysymToKeycode(dpy->display, key);

        XGrabKey(dpy->display, kc, modifier, s->root, True, GrabModeAsync, GrabModeAsync);
}

void
grab_keys (snfwm_screen *s)
{
        int i;

        i = '0';
        while (i < '9')
        {
                grab_key(s, (char) i, MODIFIER_PREFIX_REV);
                i++;
        }
        grab_key(s, KEY_PREFIX, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_XTERM, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_EMACS, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_PREVWINDOW, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_NEXTWINDOW, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_TOGGLEBAR, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_LASTWINDOW, MODIFIER_PREFIX_REV);
        grab_key(s, KEY_DELETE, MODIFIER_PREFIX_REV);
}
