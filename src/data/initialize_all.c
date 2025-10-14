#include "../../include/x11_data.h"
#include "../../include/logger.h"

void
initialize_all (void)
{
        log_info("into the function initialize_all");
        initialize_display ();
        log_info("initialize_display() went through");
        initialize_font    ();
        log_info("initialize_font() went through");
        initialize_screens ();
        log_info("initialize_screens() went through");
        initialize_atoms   ();
        log_info("initialize_atoms() went through");
        setup_errors       ();
        log_info("setup_errors() went through");
}
