#ifndef SCFWM_LINKED_LIST_H
#define SCFWM_LINKED_LIST_H

#include "common_structs.h"

extern t_window_list  *list_last         (t_window_list *begin_list);
extern t_window_list  *list_at           (t_window_list *begin_list, unsigned int n);
extern t_window_list  *list_find_window  (t_window_list *begin_list, Window window);

extern int      list_size         ();
extern int      list_is_empty     ();
extern int      list_remove       (t_window_list **begin_list, t_window_list *data_reference);

extern void     list_foreach      (t_window_list *begin_list, void (*f)(t_window_list *));
extern void     list_reverse      (t_window_list **begin_list);

extern int      comparator        (const t_window_list *w1, const t_window_list *w2);
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
