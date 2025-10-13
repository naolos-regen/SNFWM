#include "../../include/x11_helpers.h"
#include "../../include/logger.h"

x11_display *
x11_display_instance()
{
        static x11_display dp;
        static int initialized = 0;
        if (!initialized)
        {
                if (x11_init_display(&dp) < 0)
                {
                        log_fatal("failed to initialize display");
                }
                if (x11_set_masks(&dp) < 0)
                {
                        log_fatal("failed to set input masks");
                }
                initialized = 1;

        }
        return &dp;
}
