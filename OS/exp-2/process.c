#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process running with PID: %d\n", getpid());
    while(1) {
        printf("Working...\n");
        sleep(2); // Sleeps for 2 seconds
    }
    return 0;
}
