#include "lib/apue.h"

static void charatation(char *);

int main(void)
{
    pid_t    pid;
    
    TELL_WAIT();

    if ((pid = fork()) < 0) err_sys("fork error");
    else if (pid == 0) {
        WAIT_PARENT();
        charatation("output from child\n");
    }
    else {
        charatation("output from parent\n");
        TELL_CHILD(pid);
    }

    exit(0);
}


static void charatation(char *str)
{
    char    *ptr;
    int        c;

    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0; ) {
        putc(c, stdout);
    }
}
