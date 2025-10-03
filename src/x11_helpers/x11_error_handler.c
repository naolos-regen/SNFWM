#include "../../include/x11_helpers.h"

int
x11_error_handler(Display *display, const XErrorEvent *error)
{
        char buff[ERROR_BUFF_SIZE];
        return (XGetErrorText(display, error->error_code, buff, ERROR_BUFF_SIZE));
}

