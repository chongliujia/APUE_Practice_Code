#include "../lib/apue.h"

#include <sys/socket.h>

#if defined(SCM_CREDS)
#define CREDSTRUCT             cmsgcred
#define SCM_CREDTYPE           SCM_CREDS
#elif defined(SCM_CREDENTIALS)
#define CREDSTRUST             ucred
#define SCM_CREDTYPE           SCM_CREDENTIALS

