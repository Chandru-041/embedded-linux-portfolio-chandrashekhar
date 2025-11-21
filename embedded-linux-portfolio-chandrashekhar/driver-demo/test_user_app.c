#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/virt_led", O_WRONLY);
    if(fd < 0){
        printf("Failed to open device\n");
        return -1;
    }

    write(fd, "1", 1);
    sleep(1);
    write(fd, "0", 1);

    close(fd);
    return 0;
}
