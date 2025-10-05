#ifndef SNFWM_X11_EVENTS_H
#define SNFWM_X11_EVENTS_H

#include <X11/Xlib.h>

extern void (*handler[LASTEvent]) (const XEvent *);

extern void buttonpress	        (const XEvent *event);
extern void client_message	(const XEvent *event);
extern void configure_request   (const XEvent *event);
extern void configure_notify	(const XEvent *event);
extern void destroy_notify	(const XEvent *event);
extern void enter_notify	(const XEvent *event);
extern void expose		(const XEvent *event);
extern void focus_in		(const XEvent *event);
extern void keypress		(const XEvent *event);
extern void keyrelease	        (const XEvent *event);
extern void mapping_notify	(const XEvent *event);
extern void map_request	        (const XEvent *event);
extern void motion_notify	(const XEvent *event);
extern void property_notify	(const XEvent *event);
extern void unmap_notify	(const XEvent *event);


#endif
