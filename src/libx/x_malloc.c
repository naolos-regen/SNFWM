#include "../../include/libx.h"


void *
x_malloc(size_t len)
{
        void *ptr;

        ptr = malloc(len);
        if (!ptr)
                x_fatal(OUT_OF_MEMORY_MESSAGE, OUT_OF_MEMORY_ERRNO);
        return (ptr);
}
