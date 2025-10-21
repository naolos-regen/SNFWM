#ifndef SNFWM_COMMON_STRUCTS_H
#define SNFWM_COMMON_STRUCTS_H

#include <X11/Xlib.h>


#define x11_display     struct x11_dp
#define snfwm_screen    struct s_screen

#define STATE_UNMAPPED  0
#define STATE_MAPPED    1

struct s_screen
{
    GC gc_normal;
    GC bold_gc;
    XFontStruct *font;
    XWindowAttributes attr_root;
    Window root, key_window;
    int bar_raised;
    int screen_num;
    Colormap def_cmap;
};

typedef struct s_window
{
        Window window;
        int state;
        int last_access;
        snfwm_screen *screen;
        struct s_window *prev;
        struct s_window *next;
} snfwm_window;

struct x11_dp
{
    Display *display;
    Window root;
    int list_size;
    snfwm_window *head, *tail;
    snfwm_window *current;
    snfwm_screen  *screens;
};

#endif
