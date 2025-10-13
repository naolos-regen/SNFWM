#ifndef SNFWM_COMMON_STRUCTS_H
#define SNFWM_COMMON_STRUCTS_H

#include <X11/Xlib.h>


#define x11_display     struct x11_dp
#define snfwm_screen    struct s_screen
#define snfwm_window    struct s_window

#define STATE_UNMAPPED  0
#define STATE_MAPPED    1


typedef struct s_window_list
{
        snfwm_window *window;
        struct s_window_list *prev;
        struct s_window_list *next;
} t_window_list;


struct s_screen
{
    GC gc_normal;
    GC bold_gc;
    XFontStruct *font;
    XWindowAttributes attr_root;
    Window root, bar_window, key_window;
    int bar_raised;
    int screen_num;
    Colormap def_cmap;
};

struct s_window
{
    struct s_screen *screen;
    Window window;
    char *window_name;
    int state;
    int last_access;
};

struct x11_dp
{
    Display *display;
    Window root;
    t_window_list *head, *tail;
    t_window_list *current;
    snfwm_screen  *screens;
};

#endif
