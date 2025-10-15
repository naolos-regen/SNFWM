#include "../../include/x11_data.h"
#include "../../include/libx.h"

void
initialize_screens (void)
{
        int i;
        num_screens = ScreenCount(dpy->display);
        dpy->screens = (snfwm_screen *)x_malloc(sizeof(snfwm_screen) * num_screens);

        i = 0;
        while (i < num_screens)
        {
                initialize_screen(&dpy->screens[i], i);
                i++;
        }
}
