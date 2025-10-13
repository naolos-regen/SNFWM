#include "../../../include/x11_jobs.h"
#include "../../../include/x11_helpers.h"
#include "../../../include/logger.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void
spawn (char *prog)
{
        x11_display *dp;

        dp = x11_display_instance();
        if (fork() == 0)
        {
                if (fork() == 0)
                {
                        putenv(DisplayString(dp->display));
                        execlp(prog, prog, 0);
                        log_info("exec %s", prog);
                        perror(" failed");
                        exit(EXIT_FAILURE);
                }
                exit(0);
        }
        wait((int *) 0);
}
