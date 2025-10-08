#include "../../include/x11_helpers.h"
#include "../../include/logger.h"

GC
x11_create_gc(x11_display *dp, Drawable d, unsigned long valuemask, XGCValues *values)
{
    GC created;
    
    created = XCreateGC(dp->display, d, valuemask, values);
    if (NULL == created)
    {
        log_error("creating GC has failed returning (NULL) %p", created);
        return (NULL);
    }
    log_debug("successfully created GC %p", created);
    return (created);
}
