#ifndef SNFWM_X11_EVENTS_H
#define SNFWM_X11_EVENTS_H

#include <X11/Xlib.h>

extern void (*handler[LASTEvent]) (const XEvent *);

void buttonpress	(const XEvent *event);
void client_message	(const XEvent *event);
void configure_request  (const XEvent *event);
void configure_notify	(const XEvent *event);
void destroy_notify	(const XEvent *event);
void enter_notify	(const XEvent *event);
void expose		(const XEvent *event);
void focus_in		(const XEvent *event);
void keypress		(const XEvent *event);
void keyrelease	        (const XEvent *event);
void mapping_notify	(const XEvent *event);
void map_request	(const XEvent *event);
void motion_notify	(const XEvent *event);
void property_notify	(const XEvent *event);
void unmap_notify	(const XEvent *event);


#endif
