#include <stdio.h>
#include <unistd.h>

int main(void) {

    int x = 10;

    pid_t pid = fork();

    if (pid == 0) {
        x = 100;
        printf("Child: x = %d\n", x);
    } else {
        x = 200;
        printf("Parent: x = %d\n", x);
    }

    return 0;
}
