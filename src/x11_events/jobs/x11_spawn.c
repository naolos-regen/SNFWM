#include "../../../include/x11_jobs.h"
#include "../../../include/logger.h"
#include "../../../include/x11_data.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void
spawn (char *prog)
{
        if (fork() == 0)
        {
                if (fork() == 0)
                {
                        putenv(DisplayString(dpy->display));
                        execlp(prog, prog, 0);
                        log_info("exec %s", prog);
                        perror(" failed");
                        exit(EXIT_FAILURE);
                }
                exit(0);
        }
        wait((int *) 0);
}
