#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
//#include "MFRC522.h"
#include "time.h"

#include "fcntl.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "unistd.h"

int main(int argc, char *argv[]){

    int fd;
    char isOpen[7];// = "closed";

    if(argc > 1){

        char *fifo = argv[1];
        char result[255];

        mkfifo(fifo, 0666);
        fd = open(fifo, O_RDONLY /*| O_NONBLOCK*/);
        read(fd, result, 255);

        if(strcmp(result, "Access Granted") == 0){
            sprintf(isOpen, "opened");
        } else {
            sprintf(isOpen, "closed");
        }
        printf("%s %s", result, isOpen);
        //printf("%s", isOpen);

        close(fd);
    }


    return 0;
}