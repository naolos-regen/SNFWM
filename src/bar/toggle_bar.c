#include "../../include/bar.h"

void
toggle_bar (t_window_list *w)
{
        if (!hide_bar(w)) show_bar(w);
}
