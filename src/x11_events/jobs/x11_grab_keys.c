#include "../../../include/x11_config.h"
#include "../../../include/x11_data.h"
#include "../../../include/x11_jobs.h"

static void
grab_key (snfwm_screen *s, char key)
{
        XGrabKey
        (
                 dpy->display, XKeysymToKeycode(dpy->display, key), 
                 AnyModifier, s->key_window, True, 
                 GrabModeAsync, GrabModeAsync
        );
}

void
grab_keys (snfwm_screen *s)
{
        int i;

        i = '0';
        while (i < '9')
        {
                grab_key(s, (char) i);
                i++;
        }
        grab_key(s, KEY_XTERM);
        grab_key(s, KEY_EMACS);
        grab_key(s, KEY_PREVWINDOW);
        grab_key(s, KEY_NEXTWINDOW);
        grab_key(s, KEY_TOGGLEBAR);
        grab_key(s, KEY_LASTWINDOW);
        grab_key(s, KEY_DELETE);
        grab_key(s, KEY_PREFIX);
}
