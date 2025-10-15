#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include "../../include/libx.h"
#include "../../include/bar.h"
#include <signal.h>

void
sighandler (int val)
{
        log_fatal("I've been hit %d", val);
        x_fatal("ERRROR", val);
}

void
hup_handler (int val)
{
        log_fatal("restarting %d", val);
}

void
alarm_handler (int val)
{
        log_info("we don't care about %d", val);
        int i;

        i = 0;
        while (i < num_screens)
        {
                hide_bar(&dpy->screens[i]);
                i++;
        }
        XSync(dpy->display, False);
}

void
x11_error_handler(Display *dp, XErrorEvent *ev)
{
        char buff[ERROR_BUFF_SIZE];

        if (ev->request_code == X_CHANGE_WINDOW_ATTRIBUTES && ev->error_code == BadAccess)
        {
                log_fatal("Only 1 instance please");
                x_fatal("XLIB_ERROR", 1);
        }
        XGetErrorText(dp, ev->error_code, buff, ERROR_BUFF_SIZE);
        log_error("encountered: %s", buff);
}

void
setup_errors (void)
{
        XErrorHandler(x11_error_handler);
        if (signal(SIGALRM, alarm_handler) == SIG_IGN) 
                signal (SIGALRM, SIG_IGN);
        if (signal(SIGTERM, sighandler) == SIG_IGN)
                signal(SIGTERM, SIG_IGN);
        if (signal(SIGTERM, sighandler) == SIG_IGN)
                signal(SIGINT, SIG_IGN);
        if (signal(SIGHUP, hup_handler) == SIG_IGN)
                signal(SIGHUP, SIG_IGN);
}
