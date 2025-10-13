#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"

void
kill_window ()
{
        x11_display *dp;

        dp = x11_display_instance();

        if (dp->current == NULL) return;

        XKillClient(dp->display, dp->current->window->window);
}
