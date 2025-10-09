#ifndef SCFWM_LINKED_LIST_H
#define SCFWM_LINKED_LIST_H

#include "x11_data.h"

typedef struct s_window_list
{
        snfwm_window *window;
        struct s_window_list *prev;
        struct s_window_list *next;
} t_window_list;

t_window_list  *create_elem       (snfwm_window *window);
t_window_list  *list_last         (t_window_list *begin_list);
t_window_list  *list_at           (t_window_list *begin_list, unsigned int n);
t_window_list  *list_find         (t_window_list *begin_list, snfwm_window *data_reference);

int             list_reverse      (t_window_list **begin_list);
int             list_push_prefix  (t_window_list **begin_list, snfwm_window *window);
int             list_push_infix   (t_window_list **begin_list, snfwm_window *window, int pos);
int             list_push_suffix  (t_window_list **begin_list, snfwm_window *window);
int             list_size         (t_window_list *begin_list);
int             list_remove       (t_window_list **begin_list, snfwm_window *data_reference);

void            list_foreach      (t_window_list *begin_list, void (*f)(snfwm_window *));

extern int      comparator        ();
extern void     free_window       (snfwm_window *window);


#endif
