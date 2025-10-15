#include "../../include/x11_config.h"
#include "../../include/x11_data.h"
#include "../../include/libx.h"

void
initialize_font (void)
{
        font = XLoadQueryFont(dpy->display, FONT_NAME);
        if (NULL == font)
                x_fatal(FONT_MSG, FONT_ERRNO);
}
