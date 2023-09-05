#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <limits.h>

char *command_line = NULL;

void handle_signal(int signum) {
    if (signum == SIGUSR1) {
        system(command_line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    command_line = argv[1];

    if (signal(SIGUSR1, handle_signal) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    while (1) {
        sleep(UINT_MAX);
    }

    return 0;
}
