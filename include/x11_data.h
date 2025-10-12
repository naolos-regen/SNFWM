#ifndef SCFWM_X11_STRUCTS_H
#define SCFWM_X11_STRUCTS_H

#include <X11/Xlib.h>
#include "common_structs.h"

extern x11_display  *display;
extern Atom          restart;
extern t_window_list *head, *tail;
extern t_window_list *current;

#endif
