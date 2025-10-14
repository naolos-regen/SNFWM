#include "../../include/x11_config.h"
#include "../../include/x11_data.h"
#include "../../include/bar.h"
#include <stdio.h>

#define FONT_HEIGHT(f) ((f)->max_bounds.ascent + (f)->max_bounds.descent)

static size_t
strlen(const char *str)
{
        const char *sc;

        sc = str;
        while (*sc != '\0')
                ++sc;
        return sc - str;
}

static int
calc_bar_width(XFontStruct *p, t_window_list **begin_list)
{
        char str[100];
        int i;
        int size = 1;
        t_window_list *current;

        i = 0;
        current = *begin_list;
        while(current)
        {
                if (current->window->state == STATE_UNMAPPED) 
                        continue;
                sprintf(str, "%d-%s", i, current->window->window_name);
                size += 10 + XTextWidth(p, str, strlen(str));
                current = current->next;
                i++;
        }
        return (size);
}

static int
bar_x(snfwm_screen *scr, int width)
{
        if (BAR_LOCATION >= 2) return scr->attr_root.width - width;
        else return (0);
}

static int
bar_y(snfwm_screen *scr)
{
        if (BAR_LOCATION % 2) return (0);
        else return scr->attr_root.height - (FONT_HEIGHT (scr->font) + BAR_PADDING * 2) - 2;

}

void
update_window_names(snfwm_screen *s)
{
        t_window_list *current;
        char str[100];
        int i;
        int width;
        int cur_x;

        width = calc_bar_width(s->font, &dpy->head);
        cur_x = 5;
        
        if (!s->bar_raised) return;
        XMoveResizeWindow
        (
                        dpy->display, s->bar_window, 
                        bar_x (s, width), 
                        bar_y(s), width, 
                        (FONT_HEIGHT (s->font) + BAR_PADDING * 2)
        );
        XClearWindow(dpy->display, s->bar_window);
        XRaiseWindow(dpy->display, s->bar_window);

        i = 0;
        current = dpy->head;
        while (current)
        {
                if (current->window->state == STATE_UNMAPPED) continue;
                sprintf(str, "%d-%s", i, current->window->window_name);
                size_t str_len = strlen(str);
                XDrawString
                (
                                dpy->display, 
                                s->bar_window, 
                                s->gc_normal, 
                                cur_x,
                                BAR_PADDING + s->font->max_bounds.ascent, 
                                str, 
                                str_len
                );
                
                cur_x = cur_x + 10 + XTextWidth (s->font, str, str_len);
                current = current->next;
        }
}
