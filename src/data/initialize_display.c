#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include <stdlib.h>

void
initialize_display (void)
{
        log_info("we are in initialize_display");
        dpy = malloc(sizeof(x11_display));
        if (NULL == dpy)
        {
                log_fatal("out of memory");
                exit_signal = 1;
        }
        dpy->display = XOpenDisplay (NULL);
        if (NULL == dpy->display)
        {
                log_fatal("display didn't get initialized");
                exit_signal = 1;
        }
        dpy->root = XDefaultRootWindow(dpy->display);

        dpy->head = NULL;
        dpy->tail = NULL;
        dpy->current = NULL;
        dpy->screens = NULL;
}
