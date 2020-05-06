#include "whats_my_rundir.h"

int whats_my_rundir(char output[],int len_array)
{
#ifdef APPLE
    int ret;
    pid_t pid;

    pid = getpid();
    ret = proc_pidpath (pid, output, len_array);
    if ( ret <= 0 ) {
        fprintf(stderr, "PID %d: proc_pidpath ();\n", pid);
        fprintf(stderr, "    %s\n", strerror(errno));
        return 1;
    }
#else
   ssize_t r;

   if ( !output || len_array < 2 )
      return 1;

   r = readlink("/proc/self/exe", output, len_array-1);

   if (r < 0) {
        perror("lstat");
        return 1;
   }

   output[r] = '\0';
#endif
   return 0;
}

int main(int argc, char* argv[]){
    int size = 1024;
    char *output = (char *)malloc(sizeof(char)*size);
    if( whats_my_rundir(output, size) ) {
       fprintf(stderr,"** failure\n");
       return 1;
    }
    printf("Current executable is '%s'\n", output);
    free(output);
    return 0;
}
