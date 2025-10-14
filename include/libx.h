#ifndef SNFWM_LIBX_H
#define SNFWM_LIBX_H

#include <stdlib.h>

#define OUT_OF_MEMORY 69

size_t          x_strlen (const char *s);
void            x_strcpy (char *dest, char *src);
void           *x_malloc (size_t size);
void            x_exit   (int error_number);


#endif
