#include "../include/x11_helpers.h"
#include "../include/x11_data.h"

int num_screens;

int
main (void)
{
        x11_display *dp = x11_display_instance();
        x11_main_loop(dp);
        x11_free(dp);
        return (1);
}
