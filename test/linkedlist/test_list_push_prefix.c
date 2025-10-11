#include "../../include/linkedlist.h"
#include <criterion/criterion.h>

Test(list_push_prefix, basic)
{
        t_window_list *s = NULL;
        snfwm_window   w;

        list_push_prefix(&s, &w);
        cr_assert_not_null(s);
        cr_assert_null(s->prev);
        cr_assert_null(s->next);
        cr_assert_eq(s->window, &w);
}

Test(list_push_prefix, basic_two)
{
        t_window_list *s = NULL;
        snfwm_window   w1;
        snfwm_window   w2;

        list_push_prefix(&s, &w1);
        list_push_prefix(&s, &w2);
        
        cr_assert_not_null(s);
        cr_assert_eq(s->window, &w2);
        cr_assert_not_null(s->next);
        cr_assert_eq(s->next->window, &w1);
        cr_assert_eq(s->next->prev, s);
        cr_assert_null(s->prev);
}

Test(list_push_prefix, basic_three)
{
        t_window_list *s = NULL;
        
        snfwm_window   w1;
        snfwm_window   w2;
        snfwm_window   w3;

        list_push_prefix(&s, &w1);
        list_push_prefix(&s, &w2);
        list_push_prefix(&s, &w3);

        cr_assert_not_null(s);
        cr_assert_eq(s->window, &w3);
        cr_assert_not_null(s->next);
        cr_assert_eq(s->next->window, &w2);
        cr_assert_not_null(s->next->next);
        cr_assert_eq(s->next->next->window, &w1);
        cr_assert_null(s->prev);
}
