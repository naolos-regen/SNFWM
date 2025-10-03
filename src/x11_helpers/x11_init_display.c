#include "../../include/x11_helpers.h"
#include "../../include/logger.h"

int
x11_init_display (x11_display *dp)
{
	dp->display = XOpenDisplay (NULL);

	if (NULL == dp->display) {
		log_fatal("display didn't get initialized error %p", &dp);
		return (-1);
	}

	dp->root    = XDefaultRootWindow (dp->display);
	return 1;
}
