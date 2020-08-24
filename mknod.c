#include <errno.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
        errno = 0;
        mknod("mknod.c", S_IFCHR | 024, makedev(1, 7));
        if (errno != EEXIST) {
                perror("mknod");
                exit(1);
        }

        return 0;
}
