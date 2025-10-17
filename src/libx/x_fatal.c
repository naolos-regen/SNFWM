#include "../../include/libx.h"
#include "../../include/logger.h"
#include <stdlib.h>

void
x_fatal (const char *message, const int errno)
{
        log_fatal("%d : %s", errno, message);
        exit (errno);
}
