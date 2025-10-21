#include "../../include/x11_data.h"

x11_display     *dpy;
Window          key_window;
XFontStruct     *font;

Atom            restart;
Atom            wm_state;
Atom            wm_change_state;
Atom            wm_protocols;
Atom            wm_delete;
Atom            wm_take_focus;
Atom            wm_colormaps;
Atom            restart;

int             num_screens;
int             exit_signal;
