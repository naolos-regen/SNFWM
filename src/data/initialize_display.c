#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include "../../include/libx.h"
#include <stdlib.h>

void
initialize_display (void)
{
        log_info("trying to iniitalize Display");
        dpy = x_malloc(sizeof(x11_display));
        dpy->display = XOpenDisplay (NULL);
        if (NULL == dpy->display)
                x_fatal(DISPLAY_OPENED_MESSAGE, DISPLAY_OPENED_ERRNO);
        dpy->root = XDefaultRootWindow(dpy->display);
        dpy->head = NULL;
        dpy->tail = NULL;
        dpy->current = NULL;
        dpy->screens = NULL;
}
