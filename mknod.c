#include <errno.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static long
call_mknod(unsigned short mode, unsigned long dev)
{
	unsigned long lmode = (unsigned long) 0xffffffffffff0000ULL | mode;
	return syscall(__NR_mknod, "mknod.c", mode, dev);
}

int main(void)
{
        errno = 0;

	unsigned long dev = (unsigned long) 0xdeadbeef00000000ULL | makedev(1, 7);
	call_mknod(S_IFCHR | 024, dev);

        if (errno != EEXIST) {
                perror("mknod");
                exit(1);
        }

        return 0;
}
