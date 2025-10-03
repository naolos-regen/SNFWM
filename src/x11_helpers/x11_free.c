#include "../../include/x11_helpers.h"

int
x11_free (const x11_display *display)
{
	return (XCloseDisplay (display->display));
}
