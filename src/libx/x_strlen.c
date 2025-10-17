#include "../../include/libx.h"

size_t
x_strlen (const char *s)
{
        const char *p;

        p = s;
        while (*p)
                p++;
        return (p - s);
}
