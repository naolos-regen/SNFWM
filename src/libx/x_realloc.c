#include "../../include/libx.h"

void *
x_realloc (void *what, size_t how_big)
{
        void *ret;

        ret = what;
        if (NULL == ret)
                return x_malloc (how_big);
        else
                ret = realloc(what, how_big);
        if (NULL == ret)
                x_fatal(OUT_OF_MEMORY_MESSAGE, OUT_OF_MEMORY_ERRNO);
        return (ret);
}
