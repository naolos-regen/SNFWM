#include "../include/x11_helpers.h"
#include "../include/x11_data.h"
#include "../include/x11_jobs.h"
#include "../include/logger.h"
#include "../include/x11_config.h"
#include "../include/linkedlist.h"

#include <stdlib.h>


Atom     restart;
Atom     wm_state;
Atom     wm_change_state;
Atom     wm_protocols;
Atom     wm_delete;
Atom     wm_take_focus;
Atom     wm_colormaps;
int num_screens;

static XFontStruct *font;

static void
init_screen (x11_display *dp, snfwm_screen *s, int screen_num)
{
        XColor fg_color, bg_color, bold_color, junk;
        XGCValues gv;

        s->screen_num = screen_num;
        s->root = dp->root;
        s->def_cmap = XDefaultColormap (dp->display, s->screen_num);
        s->font = font;
        XGetWindowAttributes(dp->display, dp->root, &s->attr_root);

        if (!XAllocNamedColor (dp->display, s->def_cmap, BAR_FG_COLOR, &fg_color, &junk))
                log_warn("Unknown color '%s'", BAR_FG_COLOR);
        if (!XAllocNamedColor (dp->display, s->def_cmap, BAR_BG_COLOR, &bg_color, &junk))
                log_warn("Unknown color '%s'", BAR_BG_COLOR);
        if (!XAllocNamedColor (dp->display, s->def_cmap, BAR_BOLD_COLOR, &bold_color, &junk))
                log_warn("Unknown color '%s'", BAR_BOLD_COLOR);

        gv.foreground = fg_color.pixel;
        gv.background = bg_color.pixel;
        gv.function = GXcopy;
        gv.line_width = 1;
        gv.subwindow_mode = IncludeInferiors;
        gv.font = font->fid;
        s->gc_normal = XCreateGC(dp->display, dp->root, GCForeground | GCBackground | GCFunction | GCLineWidth | GCSubwindowMode | GCFont, &gv);
        gv.foreground = bold_color.pixel;
        s->bold_gc = XCreateGC(dp->display, dp->root, GCForeground | GCBackground | GCFunction | GCLineWidth | GCSubwindowMode | GCFont, &gv);

        XSelectInput(dp->display, dp->root, PropertyChangeMask | ColormapChangeMask | SubstructureRedirectMask | KeyPressMask | SubstructureNotifyMask);
        XSync(dp->display, 0);

        s->bar_raised = 0;
        s->bar_window = XCreateSimpleWindow (dp->display, dp->root, 0, 0, 1, 1, 1, fg_color.pixel, bg_color.pixel);
        s->key_window = XCreateSimpleWindow (dp->display, dp->root, 0, 0, 1, 1, 0, WhitePixel (dp->display, 0), BlackPixel(dp->display, 0));

        log_warn("hello");
        XSelectInput (dp->display, s->bar_window, SubstructureNotifyMask);
        XMapWindow (dp->display, s->key_window);
        log_debug("going into grab_keys");
        grab_keys (s);
        scan_windows (s);
}

void clean_up(x11_display *dp);

int
main (void)
{
        int i;
        x11_display *dp;

        dp = x11_display_instance();

        font = XLoadQueryFont(dp->display, FONT_NAME);
        if (font == NULL)
        {
                log_warn("cannot load font");
                exit (EXIT_FAILURE);
        }
        num_screens = ScreenCount(dp->display);
        if ((dp->screens = (snfwm_screen *)malloc(sizeof(snfwm_window) * num_screens)) == NULL)
        {
                log_warn("out of mem");
                exit(EXIT_FAILURE);
        }
        log_debug("hello");

        i = 0;
        while (i < num_screens)
        {
                init_screen(dp, &dp->screens[i], i);

                i++;
        }
        log_debug("hello 2");
        wm_state = XInternAtom(dp->display, "WM_STATE", False);
        wm_change_state = XInternAtom(dp->display, "WM_CHANGE_STATE", False);
        wm_protocols = XInternAtom(dp->display, "WM_PROTOCOLS", False);
        wm_delete = XInternAtom(dp->display, "WM_DELETE_WINDOW", False);
        wm_take_focus = XInternAtom(dp->display, "WM_TAKE_FOCUS", False);
        wm_colormaps = XInternAtom(dp->display, "WM_COLORMAP_WINDOWS", False);
        
        restart = XInternAtom (dp->display, "SNFWM_RESTART", False);

        XSync(dp->display, False);
        
        dp->current = dp->head;
        set_active_window(dp->current);
        
        x11_main_loop(dp);
        x11_free(dp);
        
        return (1);
}

void
clean_up(x11_display *dp)
{
        XSetInputFocus(dp->display, PointerRoot, RevertToPointerRoot, CurrentTime);
        XCloseDisplay(dp->display);
}
