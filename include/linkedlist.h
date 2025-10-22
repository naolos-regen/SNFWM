#ifndef SCFWM_LINKED_LIST_H
#define SCFWM_LINKED_LIST_H

#include "common_structs.h"

extern snfwm_window  *list_last         (snfwm_window *begin_list);
extern snfwm_window  *list_at           (snfwm_window *begin_list, unsigned int n);
extern snfwm_window  *list_find_window  (snfwm_window *begin_list, Window window);

extern int      list_size         ();
extern int      list_is_empty     ();
extern int      list_remove       (snfwm_window **begin_list, snfwm_window *data_reference);

extern void     list_foreach      (snfwm_window *begin_list, void (*f)(snfwm_window *));
extern void     list_reverse      (snfwm_window **begin_list);

extern int      comparator        (const snfwm_window *w1, const snfwm_window *w2);
extern void     free_list         (snfwm_window **begin_list);
extern void     free_node         (snfwm_window *node);

extern void     set_current_window(snfwm_window *window);
extern void     set_active_window (snfwm_window *window);

extern snfwm_window    *add_to_list       (snfwm_screen *s, Window w);
extern void             next_window        (void);
extern void             prev_window        (void);
extern void             last_window        (void);
extern void             goto_window_number (int n);
extern void             remove_from_window_list (snfwm_window *w);


#endif
