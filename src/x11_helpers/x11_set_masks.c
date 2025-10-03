#include "../../include/x11_helpers.h"

int
x11_set_masks(const x11_display *screen)
{
        if (1 != XSelectInput(screen->display, screen->root, X11_MASKS))
        {
                // TODO: log mask fail
                return (-1);
        }
        return (1);
}
