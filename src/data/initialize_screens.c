#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include <stdlib.h>

void
initialize_screens ()
{
        int i;
        num_screens = ScreenCount(dpy->display);
        if (NULL == (dpy->screens = (snfwm_screen *)malloc(sizeof(snfwm_screen) * num_screens)))
        {
                log_fatal("out of memory");
                exit_signal = 1;
        }

        i = 0;

        while (i < num_screens)
        {
                initialize_screen(&dpy->screens[i], i);
                i++;
        }
}
