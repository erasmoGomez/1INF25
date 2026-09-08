#include <stdio.h>
#include <unistd.h>

int main(void) {

    printf("Before fork\n");

    fork();

    printf("After fork\n");

    return 0;
}
