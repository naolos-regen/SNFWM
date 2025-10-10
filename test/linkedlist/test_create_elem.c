#include "../../include/linkedlist.h"
#include <criterion/criterion.h>

Test(create_elem, basic)
{
        int i;

        i = 0;
        while (i < 1000)
        {
                snfwm_window w =
                {
                        .window_name = "i3wm",
                        .state = 1,
                };
                t_window_list *node = create_elem(&w);
                cr_assert_not_null(node->window);
                cr_assert_eq(node->window, &w);
                cr_assert_null(node->next);
                cr_assert_null(node->prev);
                free(node);
                i++;
        }
}

Test(create_elem, create_with_null_window)
{
        t_window_list *elem = create_elem(NULL);
        cr_assert_not_null(elem);
        cr_assert_null(elem->window);
        cr_assert_null(elem->prev);
        cr_assert_null(elem->next);
        free(elem);
}

Test(window_list, link_elements)
{
        snfwm_window window1, window2, window3;
        t_window_list *elem1 = create_elem(&window1);
        t_window_list *elem2 = create_elem(&window2);
        t_window_list *elem3 = create_elem(&window3);

        elem1->next = elem2;
        elem2->prev = elem1;
        elem2->next = elem3;
        elem3->prev = elem2;

        cr_assert_eq(elem1->next, elem2, "First element's next pointer incorrect");
        cr_assert_eq(elem2->prev, elem1, "Second element's prev pointer incorrect");
        cr_assert_eq(elem2->next, elem3, "Second element's next pointer incorrect");
        cr_assert_eq(elem3->prev, elem2, "Third element's prev pointer incorrect");

        free(elem1);
        free(elem2);
        free(elem3);
}
