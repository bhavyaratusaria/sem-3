#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // 1. OPEN: Creates a file named 'example.txt'
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);

    printf("File opened successfully with descriptor: %d\n", fd);

    // 2. CLOSE: Closes the file descriptor
    close(fd);
    printf("File closed successfully.\n");

    return 0;
}
