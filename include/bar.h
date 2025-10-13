#ifndef SNFWM_BAR_H
#define SNFWM_BAR_H

#include "common_structs.h"

int     hide_bar                (snfwm_screen *s);
int     show_bar                (snfwm_screen *s);
void    toggle_bar              (snfwm_screen *s);
void    update_window_names     (snfwm_screen *s);

#endif
