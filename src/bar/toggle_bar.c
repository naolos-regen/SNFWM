#include "../../include/bar.h"

void
toggle_bar (snfwm_screen *w)
{
        if (!hide_bar(w)) show_bar(w);
}
