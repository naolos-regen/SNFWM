#include "../../include/x11_data.h"
#include "../../include/x11_helpers.h"

snfwm_screen *
find_screen(Window window)
{
        int i;

        i = 0;
        while(i < num_screens)
        {
                if (dpy->screens[i].root == window) return &dpy->screens[i];
                i++;
        }
        return (NULL);
}
