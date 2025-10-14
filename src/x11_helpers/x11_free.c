#include "../../include/x11_helpers.h"

int
x11_free (void)
{
	return (XCloseDisplay (dpy->display));
}
