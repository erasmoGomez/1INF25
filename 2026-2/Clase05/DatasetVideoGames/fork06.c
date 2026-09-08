#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {

        printf("Child: starting...\n");
        sleep(2);
        printf("Child: finished.\n");

        exit(42);

    } else {

        int status;

        printf("Parent: waiting...\n");

        waitpid(pid, &status, 0);

        printf("Parent: child finished.\n");

        if (WIFEXITED(status)) {
            printf(
                "Exit status = %d\n",
                WEXITSTATUS(status)
            );
        }
    }

    return 0;
}
