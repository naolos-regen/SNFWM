#include "../../include/x11_data.h"

void
initialize_atoms (void)
{
        wm_state = XInternAtom(dpy->display, "WM_STATE", False);
        wm_change_state = XInternAtom(dpy->display, "WM_CHANGE_STATE", False);
        wm_protocols = XInternAtom(dpy->display, "WM_PROTOCOLS", False);
        wm_delete = XInternAtom(dpy->display, "WM_DELETE_WINDOW", False);
        wm_take_focus = XInternAtom(dpy->display, "WM_TAKE_FOCUS", False);
        wm_colormaps = XInternAtom(dpy->display, "WM_COLORMAP_WINDOWS", False);

        restart = XInternAtom (dpy->display, "SNFWM_RESTART", False);
}
