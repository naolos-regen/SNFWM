#include "../../include/x11_helpers.h"

int
x11_free ()
{
	return (XCloseDisplay (dpy->display));
}
