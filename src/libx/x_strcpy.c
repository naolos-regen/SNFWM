#include "../../include/libx.h"

void
x_strcpy(char *dest, char *src)
{
        while ((*dest++ = *src++) != '\0')
                ;
}
