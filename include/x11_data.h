#ifndef SCFWM_X11_STRUCTS_H
#define SCFWM_X11_STRUCTS_H

#include <X11/Xlib.h>
#include "common_structs.h"

#define ERROR_BUFF_SIZE 256
#define X_CHANGE_WINDOW_ATTRIBUTES 2

extern x11_display      *dpy;
extern XFontStruct      *font;
extern int              num_screens;
extern Atom             restart;
extern Atom             wm_state;
extern Atom             wm_change_state;
extern Atom             wm_protocols;
extern Atom             wm_delete;
extern Atom             wm_take_focus;
extern Atom             wm_colormaps;

extern int exit_signal;

extern void initialize_screen  (snfwm_screen *s, int i);
extern void initialize_display ();
extern void initialize_font    ();
extern void initialize_screens ();
extern void initialize_atoms   ();
extern void initialize_all     ();
extern void setup_errors       ();

#endif
