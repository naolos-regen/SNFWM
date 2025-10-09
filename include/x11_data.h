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
    struct s_window *next, *prev;
};

struct x11_dp
{
    Display *display;
    Window root;
};


extern snfwm_window *head;
extern snfwm_window *tail;
extern snfwm_window *curr;

extern x11_display  *display;
extern Atom          restart;

#endif
