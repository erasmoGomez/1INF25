#include <stdio.h>
#include <unistd.h>

int main(void) {

    printf("Before fork: PID=%d\n", getpid());

    pid_t pid = fork();

    printf(
        "After fork: PID=%d PPID=%d fork_return=%d\n",
        getpid(),
        getppid(),
        pid
    );

    return 0;
}
