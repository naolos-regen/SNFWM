#include "../../include/x11_helpers.h"

int
x11_set_masks (void)
{
	if (1 != XSelectInput (dpy->display, dpy->root, X11_MASKS)) {
		return (-1);
	}
	return (1);
}
