#include "../../include/x11_helpers.h"

int
x11_init_display(x11_display *dp)
{
        dp->display = XOpenDisplay(NULL);
        if (NULL == dp->display)
        {
                return (-1);
        }
        dp->root    = XDefaultRootWindow(dp->display);
        return 1;
}
