#include "../../include/x11_helpers.h"

int
x11_free (x11_display *dp)
{
	return (XCloseDisplay (dp->display));
}
