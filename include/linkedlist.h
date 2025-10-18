#ifndef SCFWM_LINKED_LIST_H
#define SCFWM_LINKED_LIST_H

#include "common_structs.h"

t_window_list  *create_elem       (snfwm_window *window);
t_window_list  *list_last         (t_window_list *begin_list);
t_window_list  *list_at           (t_window_list *begin_list, unsigned int n);
t_window_list  *list_find         (t_window_list *begin_list, snfwm_window *data_reference);
t_window_list  *list_find_window  (t_window_list *begin_list, Window window);

int             list_push_prefix  (t_window_list **begin_list, snfwm_window *window);
int             list_push_infix   (t_window_list **begin_list, snfwm_window *window, int pos);
int             list_push_suffix  (t_window_list **begin_list, snfwm_window *window);
int             list_size         (t_window_list *begin_list);
int             list_is_empty     (t_window_list *begin_list);
int             list_remove       (t_window_list **begin_list, snfwm_window *data_reference);

void            list_foreach      (t_window_list *begin_list, void (*f)(snfwm_window *));
void            list_reverse      (t_window_list **begin_list);

extern int      comparator        (const snfwm_window *w1, const snfwm_window *w2);
extern void     free_window       (snfwm_window *window);
extern void     free_list         (t_window_list **begin_list);
extern void     free_node         (t_window_list *node);

extern void     set_current_window(t_window_list *window);
extern void     set_active_window (t_window_list *window);

extern t_window_list    *add_to_list       (snfwm_screen *s, Window w);
extern void             next_window        (void);
extern void             prev_window        (void);
extern void             last_window        (void);
extern void             goto_window_number (int n);


#endif
