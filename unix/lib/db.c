#include "apue.h"
#include "apue_db.h"


#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/uio.h>



#define  IDXLEN_SZ    4
#define  SEP         ':'
#define  SPACE       ' '
#define  NEWLINE     '\n'



#define  PTR_SZ        7
#define  PTR_MAX  999999
#define  NHASH_DEF   137
#define  FREE_OFF      0
#define  HASH_OFF PTR_SZ


typedef  unsigned long DBHASH;
typedef  unsigned long COUNT;

