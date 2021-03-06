#include "../lib/opend.h"

#include <fcntl.h>



void
handle_request(char *buf, int nread, int fd)
{
    int      newfd;

    if (buf[nread - 1] != 0) {
        snprintf(errmsg, MAXLINE - 1, 
                "request not null terminated: %*.*\n", nread, nread, buf);
        send_err(fd, -1, errmsg);
        return ;
    }

    if (buf_args(buf, cli_args) < 0) {
        send_err(fd, -1, errmsg);
        return ;
    }

    if ((newfd = open(pathname, oflag)) < 0) {
        snprintf(errmsg, MAXLINE - 1, "can't open %s:%s\n", pathname, strerror(errno));
        send_err(fd, -1, errmsg);
        return ;
    }

    if (send_fd(fd, newfd) < 0) {
        err_sys("send_fd error");
    }

    close(newfd);
}
