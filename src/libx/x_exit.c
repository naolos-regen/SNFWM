#include "../../include/libx.h"
#include "../../include/logger.h"

void
x_exit (int errno)
{
        /* TODO: I have thought of getting stack-based-error or 
         *       who called the function smoothen up the 
         *       finding processes.
         *       maybe it's possible (but it will cost extra heap)
         */
        switch (errno)
        {
                case OUT_OF_MEMORY: log_fatal("Out of memory error"); break;
        }
        exit(errno);
}
