#include "../../include/x11_config.h"
#include "../../include/x11_data.h"
#include "../../include/logger.h"


void
initialize_font (void)
{
        font = XLoadQueryFont(dpy->display, FONT_NAME);
        if (NULL == font)
        {
                log_warn("cannot load the font");
                exit_signal = 1;
        }
}
