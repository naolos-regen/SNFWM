#include "../../include/linkedlist.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <limits.h>

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

Test(list_push_suffix, advanced)
{
        int ammount = INT_MAX;
        int index;
        snfwm_window *placeholder = malloc(sizeof(snfwm_window) * ammount);
        if (!placeholder)
        {
                return;
        }
        t_window_list *s = NULL;
        index = 0;
        while (index < ammount)
        {
                char str[32];
                sprintf(str, "%d", index);
                placeholder[index].window_name = strdup(str);
                list_push_suffix(&s, &placeholder[index]);
                index++;
        }

        t_window_list *node = s;
        index = 0;
        while (index < ammount && node != NULL)
        {
                cr_assert_eq(node->window, &placeholder[index]);
                node = node->next;
                index++;
        }

        index = 0;
        while (index < ammount)
        {
                free((char *)placeholder[index].window_name);
                index++;
        }
        free(placeholder);

        while (!s)
        {
                t_window_list *tmp = s;
                s = s->next;
                free(tmp);
        }
}
