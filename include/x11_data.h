#ifndef SCFWM_X11_STRUCTS_H
#define SCFWM_X11_STRUCTS_H

#include <X11/Xlib.h>

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
        struct s_window *next, *prev;      
};

#endif
