#include "../../include/libx.h"

void *
x_malloc(size_t len)
{
        void *ptr;

        ptr = malloc(len);
        if (!ptr)
                x_exit(OUT_OF_MEMORY);
        return (ptr);
}
