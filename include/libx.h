#ifndef SNFWM_LIBX_H
#define SNFWM_LIBX_H

#include <stdlib.h>

#define OUT_OF_MEMORY_ERRNO     69
#define OUT_OF_MEMORY_MESSAGE   "Malloc::Out_of_memory"
#define DISPLAY_OPENED_ERRNO    42
#define DISPLAY_OPENED_MESSAGE  "Xlib::Display_alrady_open"
#define FONT_MSG                "Xlib::Font_not_exists"
#define FONT_ERRNO              20

size_t          x_strlen (const char *s);
void            x_strcpy (char *dest, char *src);
void           *x_malloc (size_t size);
void            x_fatal  (const char *msg, const int errno);

#endif
