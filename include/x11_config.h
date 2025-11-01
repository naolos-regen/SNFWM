#ifndef SCFWM_X11_CONFIG_H
#define SCFWM_X11_CONFIG_H

#include <X11/keysym.h>

#define MODIFIER_PREFIX_REV Mod4Mask

#define MODIFIER_PREFIX ControlMask
#define KEY_PREFIX      't'


#define KEY_XTERM       'c'
#define KEY_EMACS       'e'
#define KEY_PREVWINDOW  'p'
#define KEY_NEXTWINDOW  'n'
#define KEY_LASTWINDOW  't'	
#define KEY_TOGGLEBAR   'w'
#define KEY_DELETE      'm'

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
