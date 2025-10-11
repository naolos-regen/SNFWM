#include "../../include/linkedlist.h"
#include <criterion/criterion.h>

Test(list_push_suffix, basic)
{
        t_window_list *s = NULL;
        snfwm_window   w = { .window_name = "lo" };

        list_push_suffix(&s, &w);
        cr_assert_not_null(s);
        cr_assert_eq(s->window, &w);
        cr_assert_null(s->next);
        cr_assert_null(s->prev);
}

Test(list_push_suffix, basic_two)
{
        t_window_list *s = NULL;
        snfwm_window   w1 = { .window_name = "lo" };
        snfwm_window   w2 = { .window_name = "ol" };

        list_push_suffix(&s, &w1);
        list_push_suffix(&s, &w2);
        cr_assert_not_null(s);
        cr_assert_eq(s->window, &w1);
        cr_assert_not_null(s->next);
        cr_assert_null(s->prev);
        cr_assert_eq(s->next->window, &w2);
}

Test(list_push_suffix, basic_three)
{
        t_window_list *s = NULL;
        snfwm_window   w1 = { .window_name = "lo" };
        snfwm_window   w2 = { .window_name = "ol" };
        snfwm_window   w3 = { .window_name = "el" };

        list_push_suffix(&s, &w1);
        list_push_suffix(&s, &w2);
        list_push_suffix(&s, &w3);

        cr_assert_not_null(s);
        cr_assert_eq(s->window, &w1);
        cr_assert_not_null(s->next);
        cr_assert_not_null(s->next->next);
        cr_assert_eq(s->next->window, &w2);
        cr_assert_eq(s->next->next->window, &w3);
        cr_assert_null(s->prev);
}
