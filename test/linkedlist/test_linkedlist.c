#include <criterion/criterion.h>
#include "../../include/linkedlist.h"
#include <stdlib.h>
#include <string.h>

snfwm_window *create_test_window(const char* name, unsigned long id)
{
        snfwm_window *w = malloc(sizeof(snfwm_window));
        w->window = id;
        w->window_name = strdup(name);
        return (w);
}

void dummy_free_window(snfwm_window *window)
{
        if (!window) return;
        free((void*)window->window_name);
        free(window);
}

void dummy_func(snfwm_window *w)
{
        (void)w;
}

void dummy_free_list(t_window_list *list)
{
        t_window_list *current;
        
        if (!list)
                return;

        current = list;
        while (current)
        {
                dummy_free_window(current->window);
                current = current->next;
        }
}

Test(linkedlist, create_and_free_elem)
{
        snfwm_window *win = create_test_window("test", 42);
        t_window_list *node = create_elem(win);

        cr_assert_not_null(node);
        cr_assert_eq(node->window, win);
        cr_assert_null(node->next);
        cr_assert_null(node->prev);

        dummy_free_window(win);
        free(node);
}

Test(linkedlist, push_pre_and_suf_fix)
{
        t_window_list *list = NULL;
        snfwm_window *win1 = create_test_window("prefix", 1);
        snfwm_window *win2 = create_test_window("suffix", 2);

        list_push_prefix(&list, win1);
        list_push_suffix(&list, win2);

        cr_assert_str_eq(list->window->window_name, "prefix");
        cr_assert_str_eq(list->next->window->window_name, "suffix");

        dummy_free_list(list);
}

Test(linkedlist, list_push_infix)
{
        t_window_list *list = NULL;
        snfwm_window *w1 = create_test_window("1", 1);
        snfwm_window *w2 = create_test_window("2", 2);
        snfwm_window *w3 = create_test_window("3", 3);

        list_push_suffix(&list, w1);
        list_push_suffix(&list, w3);
        list_push_infix(&list, w2, 2);

        t_window_list *n = list->next;
        cr_assert_str_eq(n->window->window_name, "2");

        dummy_free_list(list);
}

Test(linkedlist, list_size_and_is_empty)
{
        t_window_list *list = NULL;
        cr_assert_eq(list_is_empty(list), 1);

        snfwm_window *w = create_test_window("a", 1);
        list_push_prefix(&list, w);
        cr_assert_eq(list_size(list), 1);
        cr_assert_eq(list_is_empty(list), 0);

        dummy_free_list(list);
}

Test(linkedlist, list_at_and_last)
{
        t_window_list *list = NULL;
        snfwm_window *w1 = create_test_window("a", 1);
        snfwm_window *w2 = create_test_window("b", 2);
        list_push_suffix(&list, w1);
        list_push_suffix(&list, w2);

        t_window_list *at0 = list_at(list, 0);
        t_window_list *at1 = list_at(list, 1);
        cr_assert_str_eq(at0->window->window_name, "a");
        cr_assert_str_eq(at1->window->window_name, "b");

        dummy_free_list(list);
}

Test(linkedlist, list_find)
{
        t_window_list *list = NULL;
        snfwm_window *target = create_test_window("target", 123);
        list_push_prefix(&list, target);

        snfwm_window *search = create_test_window("target", 123);
        t_window_list *found = list_find(list, search);
        cr_assert_not_null(found);

        dummy_free_list(list);
}

Test(linkedlist, list_remove)
{
        t_window_list *list = NULL;

        snfwm_window *a = create_test_window("a", 1);
        snfwm_window *b = create_test_window("b", 2);

        list_push_suffix(&list, a);
        list_push_suffix(&list, b);

        snfwm_window *to_remove = create_test_window("a", 1);
        list_remove(&list, to_remove);
        dummy_free_window(to_remove); 

        cr_assert_eq(list_size(list), 1);
        cr_assert_str_eq(list->window->window_name, "b");

        dummy_free_list(list);
}


Test(linkedlist, list_reverse)
{
        t_window_list *list = NULL;
        snfwm_window *w1 = create_test_window("1", 1);
        snfwm_window *w2 = create_test_window("2", 2);
        list_push_suffix(&list, w1);
        list_push_suffix(&list, w2);

        list_reverse(&list);

        cr_assert_str_eq(list->window->window_name, "2");
        cr_assert_str_eq(list->next->window->window_name, "1");

        dummy_free_list(list);
}

Test(linkedlist, comparator)
{
        snfwm_window *w1 = create_test_window("abc", 10);
        snfwm_window *w2 = create_test_window("abc", 10);
        snfwm_window *w3 = create_test_window("xyz", 20);

        cr_assert_eq(comparator(w1, w2), 0);
        cr_assert_neq(comparator(w1, w3), 0);

        dummy_free_window(w1);
        dummy_free_window(w2);
        dummy_free_window(w3);
}

Test(linkedlist, foreach_calls_function)
{
        t_window_list *list = NULL;
        snfwm_window *w1 = create_test_window("a", 1);
        snfwm_window *w2 = create_test_window("b", 2);
        list_push_suffix(&list, w1);
        list_push_suffix(&list, w2);

        // No assertion here, just to verify it doesn't crash
        list_foreach(list, dummy_func);

        dummy_free_list(list);
}
