#include "whats_my_rundir.h"

char *whats_my_rundir(char output[],int len)
{
#ifdef APPLE
    int ret;
    pid_t pid;
    char linkname[PROC_PIDPATHINFO_MAXSIZE];

    pid = getpid();
    ret = proc_pidpath (pid, linkname, sizeof(linkname));
    if ( ret <= 0 ) {
        fprintf(stderr, "PID %d: proc_pidpath ();\n", pid);
        fprintf(stderr, "    %s\n", strerror(errno));
    }
    for (int i=0; i<sizeof(linkname); i++)
              {
                output[i] = linkname[i];
              }
#else


    char *linkname;
    ssize_t r;
    int sb = 1024;

   linkname = malloc(sb + 1);
    if (linkname == NULL) {
        fprintf(stderr, "insufficient memory\n");
        exit(EXIT_FAILURE);
    }

   r = readlink("/proc/self/exe", linkname, sb + 1);

   if (r < 0) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }


   linkname[sb] = '\0';


for (int i=0; i<sb; i++)
              {
                output[i] = linkname[i];
              }
#endif
   return 0;

}

   
int main(int argc, char* argv[]){
   int size = 65536;
   char output[size];
   whats_my_rundir(output,size);
   printf("Current executable is '%s'\n", output);

}
