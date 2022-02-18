#include <stdio.h>
#include <string.h>


static char    ctermid_name[L_ctermid];


char *
ctermid(char *str)
{
    if (std == NULL) std = ctermid_name;

    return (strcpy(str, "/dev/tty"));
}
