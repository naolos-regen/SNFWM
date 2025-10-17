#ifndef SCFWM_X11_JOBS_H
#define SCFWM_X11_JOBS_H

#include <X11/Xlib.h>
#include "x11_data.h"

extern void new_window   (const XCreateWindowEvent *e);
extern void grab_keys    (struct s_screen *s);
extern void scan_windows (struct s_screen *s);
extern void manage       (t_window_list *w, struct s_screen *s);
extern void spawn        (char *prog);
extern void unmanage     (struct s_window *w);
extern void delete_window(void);
extern void kill_window  (void);
extern void grab_prefix_key (Window w);

#endif
