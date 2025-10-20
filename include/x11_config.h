#ifndef SCFWM_X11_CONFIG_H
#define SCFWM_X11_CONFIG_H

#include <X11/keysym.h>

#define MODIFIER_PREFIX Mod4Mask

#define KEY_XTERM       XK_c
#define KEY_EMACS       XK_e
#define KEY_PREVWINDOW  XK_p
#define KEY_NEXTWINDOW  XK_n
#define KEY_LASTWINDOW  XK_t	
#define KEY_TOGGLEBAR   XK_w
#define KEY_DELETE      XK_k	

#define TERM_PROG       "alacritty"	
#define EMACS_PROG      "emacs"	

#define BAR_FG_COLOR    "Gray60"
#define BAR_BG_COLOR    "Lightgreen"
#define BAR_BOLD_COLOR  "Black" 

#define FONT_NAME       "fixed"	
#define BAR_PADDING     3	
#define BAR_LOCATION    3	
#define BAR_TIMEOUT     5	

#endif
