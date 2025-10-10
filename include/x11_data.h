#ifndef SCFWM_X11_STRUCTS_H
#define SCFWM_X11_STRUCTS_H

#include <X11/Xlib.h>

#define x11_display     struct x11_dp
#define snfwm_screen    struct s_screen
#define snfwm_window    struct s_window

struct s_screen
{
    GC gc_normal;
    GC bold_gc;
    XFontStruct *font;
    XWindowAttributes attr_root;
};

struct s_window
{
    struct s_screen *screen;
    Window window;
    char *window_name;
    int state;
};

struct x11_dp
{
    Display *display;
    Window root;
};

extern x11_display  *display;
extern Atom          restart;

#endif
