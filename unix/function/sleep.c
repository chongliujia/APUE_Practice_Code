#include "lib/apue.h"

static void 
sig_alrm(int signo)
{
}

unsigned int
sleep(unsigned int seconds)
{
    struct sigaction   newact, oldact;
    sigset_t           newmask, oldmask, suspmask;
    unsigned int       unslept;


    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);

    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    alarm(seconds);
    suspmask = oldmask;

    sigdelset(&suspmask, SIGALRM);

    unslept = alarm(0);

    sigaction(SIGALRM, &oldset, NULL);

    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    return (unslept);
}
