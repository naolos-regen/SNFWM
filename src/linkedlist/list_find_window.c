#include "../../include/linkedlist.h"
#include "../../include/logger.h"

t_window_list
*list_find_window(t_window_list *begin_list, Window window)
{
        log_info("entered list_find_window, begin_list = %p", begin_list);
        t_window_list *current = begin_list;

        while (current != NULL)
        {
                log_debug("current node = %p", current);
                log_debug("checking current->window = %p", current->window);

                if (current->window)
                {
                        log_debug("current->window->window = %lu", current->window->window);
                        if (current->window->window == window)
                                return current;
                }
                else
                {
                        log_warn("current->window is NULL!");
                }

                current = current->next;
        }
        return NULL;
}
