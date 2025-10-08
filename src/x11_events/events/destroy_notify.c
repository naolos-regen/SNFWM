#include "../../../include/x11_events.h"
#include "../../../include/logger.h"

/* TODO: What needs to be implemented is sort of a way to store all windows/screens 
 *       and find corresponding window that we try to remove using XDestroyNotifyEvent
 *       so first of all i need to create a list innit 
 */
void destroy_notify(const XEvent *event)
{
    log_info("to implement");
}
