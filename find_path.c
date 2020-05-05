#include "find_path.h"


int main (int argc, char* argv[])
{
    int ret;
    pid_t pid; 
    char pathbuf[PROC_PIDPATHINFO_MAXSIZE];

    pid = getpid();
    ret = proc_pidpath (pid, pathbuf, sizeof(pathbuf));
    if ( ret <= 0 ) {
        fprintf(stderr, "PID %d: proc_pidpath ();\n", pid);
        fprintf(stderr, "    %s\n", strerror(errno));
    } else {
        printf("proc %d: %s\n", pid, pathbuf);
    }

    return 0;
}