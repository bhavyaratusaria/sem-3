#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
   int p[2]; char buf[6];
   pipe(p);
   printf("Parent PID: %d\n", getpid()); // 1. getpid

    if (fork() == 0) { // 2. fork
	write(p[1], "Hi OS", 5); // 1st: Write data to pipe
        printf("Child PID: %d. Running exec...\n", getpid());
        execlp("date", "date", NULL); // 3. exec (runs the 'date' command)
}
    else {
        sleep(1); // Wait 1 second for child to finish
        read(p[0], buf, 5);
	printf("Parent read: %s\n", buf);
        printf("Parent exiting.\n");
        exit(0); // 4. exit
    }
}
