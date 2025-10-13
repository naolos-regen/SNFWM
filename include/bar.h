#ifndef SNFWM_BAR_H
#define SNFWM_BAR_H

#include "common_structs.h"

int     hide_bar                (t_window_list *w);
int     show_bar                (t_window_list *w);
void    toggle_bar              (t_window_list *w);
void    update_window_names     (t_window_list *w);

#endif
