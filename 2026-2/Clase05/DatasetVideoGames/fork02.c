#include <stdio.h>
#include <unistd.h>

int main(void) {

    pid_t result = fork();

    printf("fork returned: %d\n", result);

    return 0;
}
