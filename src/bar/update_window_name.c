#include "../../include/bar.h"
#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include "../../include/libx.h"

#include <X11/Xutil.h>

static int
failed (const int return_num, const char *str_to_log)
{
        log_error(str_to_log);
        return (return_num);
}

int
update_window_name (snfwm_window *win)
{
        XTextProperty text;
        char **name_list;
        int list_len;

        if (!XGetWMName (dpy->display, win->window, &text))
                return failed(0, "can't get the WMName.");
        if (!XTextPropertyToStringList(&text, &name_list, &list_len))
                return failed(0, "Xutil::Error recieving TextList");
        
        if (list_len > 0)
        {
                char *loc;
                free (win->window_name);
                win->window_name = x_malloc(x_strlen(name_list[0] + 1));
                x_strcpy(win->window_name, name_list[0]);
        }
        XFreeStringList(name_list);
        return (1);
}
