#include "../../../include/x11_jobs.h"
#include "../../../include/x11_data.h"
#include "../../../include/x11_config.h"

void
grab_prefix_key (Window w)
{
        XGrabKey(dpy->display, XKeysymToKeycode(dpy->display, KEY_PREFIX), MODIFIER_PREFIX, w, True, GrabModeAsync, GrabModeAsync);
}
