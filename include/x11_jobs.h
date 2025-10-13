#ifndef SCFWM_X11_JOBS_H
#define SCFWM_X11_JOBS_H

#include <X11/Xlib.h>
#include "x11_data.h"

extern void new_window   (t_window_list *w, const XCreateWindowEvent *e);
extern void grab_keys    (struct s_screen *s);
extern void scan_windows (struct s_screen *s);
extern void manage       (struct s_window *w, struct s_screen *s);
extern void spawn        (char *prog);
extern void unmanage     (struct s_window *w);
extern void delete_window();
extern void kill_window  ();

#endif
