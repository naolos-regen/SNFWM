#include "../../include/x11_data.h"
#include "../../include/logger.h"
#include "../../include/x11_config.h"
#include "../../include/x11_jobs.h"

void
initialize_screen (snfwm_screen *s, int screen_num)
{
        XColor fg_color, bg_color, bold_color, junk;
        XGCValues gv;

        s->screen_num = screen_num;
        s->root = dpy->root;
        s->def_cmap = XDefaultColormap (dpy->display, s->screen_num);
        s->font = font;
        XGetWindowAttributes(dpy->display, dpy->root, &s->attr_root);

        if (!XAllocNamedColor (dpy->display, s->def_cmap, BAR_FG_COLOR, &fg_color, &junk))
                log_warn("Unknown color '%s'", BAR_FG_COLOR);
        if (!XAllocNamedColor (dpy->display, s->def_cmap, BAR_BG_COLOR, &bg_color, &junk))
                log_warn("Unknown color '%s'", BAR_BG_COLOR);
        if (!XAllocNamedColor (dpy->display, s->def_cmap, BAR_BOLD_COLOR, &bold_color, &junk))
                log_warn("Unknown color '%s'", BAR_BOLD_COLOR);

        gv.foreground = fg_color.pixel;
        gv.background = bg_color.pixel;
        gv.function = GXcopy;
        gv.line_width = 1;
        gv.subwindow_mode = IncludeInferiors;
        gv.font = font->fid;
        s->gc_normal = XCreateGC(dpy->display, dpy->root, GCForeground | GCBackground | GCFunction | GCLineWidth | GCSubwindowMode | GCFont, &gv);
        gv.foreground = bold_color.pixel;
        s->bold_gc = XCreateGC(dpy->display, dpy->root, GCForeground | GCBackground | GCFunction | GCLineWidth | GCSubwindowMode | GCFont, &gv);

        XSelectInput(dpy->display, dpy->root, PropertyChangeMask | ColormapChangeMask | SubstructureRedirectMask | KeyPressMask | SubstructureNotifyMask);
        XSync(dpy->display, 0);

        s->bar_raised = 0;
        s->bar_window = XCreateSimpleWindow (dpy->display, dpy->root, 0, 0, 1, 1, 1, fg_color.pixel, bg_color.pixel);
        s->key_window = XCreateSimpleWindow (dpy->display, dpy->root, 0, 0, 1, 1, 0, WhitePixel (dpy->display, 0), BlackPixel(dpy->display, 0));

        log_warn("hello");
        XSelectInput (dpy->display, s->bar_window, SubstructureNotifyMask);
        XMapWindow (dpy->display, s->key_window);
        log_debug("going into grab_keys");
        grab_keys (s);
        scan_windows (s);
}

