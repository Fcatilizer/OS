#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (fork() == 0) {
            printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
            exit(0);
        }
    }

    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }

    fork();
    return 0;
}
