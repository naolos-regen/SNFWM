#include "../../include/linkedlist.h"

static
int ft_strcmp(const char *str1, const char *str2)
{
        const unsigned char *s1 = (const unsigned char *)str1;
        const unsigned char *s2 = (const unsigned char *)str2;
        int delta;

        while(*s1 || *s2)
        {
                delta = *s1 - *s2;
                if (delta)
                        return (delta);
                s1++;
                s2++;
        }
        return (0);
}

/*
 * since snfwm_window has a placeholder for Window 
 * and it's unsigned long internally
 * one can just take - expression
 * other way is to also compare title_names
 */
int
comparator(const snfwm_window *w1, const snfwm_window *w2)
{
        if (w1->window < w2->window)
                return (-1);
        if (w1->window > w2->window)
                return (1);
        return ft_strcmp(w1->window_name, w2->window_name);
}
