#include "../../include/x11_data.h"

void
initialize_all (void)
{
        initialize_display ();
        initialize_font    ();
        initialize_screens ();
        initialize_atoms   ();
        setup_errors       ();
}
