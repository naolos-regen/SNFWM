#include "../include/x11_data.h"
#include "../include/x11_helpers.h"

int
main (void)
{
        initialize_all();
        x11_main_loop ();
        x11_free      ();
        return (1);
}
