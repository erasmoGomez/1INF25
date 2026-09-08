#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    pid_t pid = fork();

    if (pid < 0) {

        perror("fork");
        return 1;

    } else if (pid == 0) {

        printf("I am the CHILD. PID=%d\n", getpid());

    } else {

        printf(
            "I am the PARENT. PID=%d, child=%d\n",
            getpid(),
            pid
        );

    }

    return 0;
}
