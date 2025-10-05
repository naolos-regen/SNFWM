#!/bin/bash

find events -type f -exec truncate -s 0 {} \;

find events -type f | xargs -I{} sh -c '
    filepath="{}"
    filename=$(basename "$filepath" .c)
    cat > "$filepath" << EOL
#include "../../../include/x11_events.h"
#include "../../../include/logger.h"

void ${filename}(const XEvent *event)
{
    log_info("to implement");
}
EOL
'

