#include <errno.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
        errno = 0;

	syscall(__NR_mknod, "mknod.c", S_IFCHR | 0777, (unsigned long) 0xdeadbeef00000000ULL | makedev(1, 7));

        if (errno != EEXIST) {
                perror("mknod");
                exit(1);
        }

        return 0;
}
