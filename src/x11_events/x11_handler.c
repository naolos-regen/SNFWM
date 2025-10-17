#include "../../include/x11_events.h"

void (*handler[LASTEvent])(const XEvent *) =
{
        [ButtonPress]           = buttonpress,
        [ClientMessage]         = client_message,
        [CreateNotify]          = create_notify,
        [ConfigureRequest]      = configure_request,
        [ConfigureNotify]       = configure_notify,
        [DestroyNotify]         = destroy_notify,
        [EnterNotify]           = enter_notify,
        [Expose]                = expose,
        [FocusIn]               = focus_in,
        [KeyPress]              = keypress,
        [KeyRelease]            = keyrelease,
        [MappingNotify]         = mapping_notify,
        [MapRequest]            = map_request,
        [PropertyNotify]        = property_notify,
        [UnmapNotify]           = unmap_notify
};
