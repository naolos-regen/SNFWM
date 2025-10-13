#include "../../include/x11_data.h"
#include "../../include/x11_helpers.h"

snfwm_screen *
find_screen(Window window)
{
        int i;

        i = 0;
        x11_display *dp = x11_display_instance();
        while(i < num_screens)
        {
                if (dp->screens[i].root == window) return &dp->screens[i];
                i++;
        }
        return (NULL);
}
