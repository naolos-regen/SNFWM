#ifndef SCFWM_X11_STRUCTS_H
#define SCFWM_X11_STRUCTS_H

#include <X11/Xlib.h>
#include "common_structs.h"

extern int      num_screens;
extern Atom     restart;
extern Atom     wm_state;
extern Atom     wm_change_state;
extern Atom     wm_protocols;
extern Atom     wm_delete;
extern Atom     wm_take_focus;
extern Atom     wm_colormaps;

extern int exit_signal;

#endif
