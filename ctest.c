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

struct tm *local;
time_t t;

void help()
{
	printf("    Use this application for reading from rfid reader\n");
	printf("    execute format: ./rfid_reader [-h][-q] \n");
	printf("    return: Card ID\n");
	printf("    -h - help\n");
	printf("    -q - quiet\n");
    printf("    ./programm pipeName\n");
}

int main(int argc, char *argv[]){

    if(argc > 1){
        if((strcmp(argv[1], "-h") == 0)){
            help();
			return 0;
        }
    }

    char uid[14] = {"91", "2d", "0c", "26"};
    char t1[14]; 
	sprintf(t1 ,"%c %c %c %c", uid[0], uid[1], uid[2], uid[3]);
	//printf("%s", t1);
			
	//if(strcmp(t1, "91 2d 0c 26") == 0){
	//	printf("GOOD");
	//}
	//t = time(NULL);
	//local = localtime(&t);
	//printf("%02x %02x %02x %02x %s\n", uid[0], uid[1], uid[2], uid[3], asctime(local));
	//fflush(stdout);
	//sleep(1);

    int fd;
    char *fifo;// = "tPipe";

    char result[255];
    //char *ft = argv[1];
    

    //Check for external arguments
    // take second argument if you are using -q mode

    fifo = argv[1];
    
    if(argc > 1){
        //fifo = argv[2];
        printf("Hello");
    }
    //} //else if(argc >= 1) {
        //fifo = argv[1];
    //}
    
    //fifo = argv[1];
    printf("%s", fifo);

    printf("\n");

    mkfifo(fifo, 0666);


    sprintf(result, "%s", "Access granted");

    printf("%s", result);
    printf("\n");

    //fd = open(fifo, O_RDWR);
    //write(fd, result, strlen(result) + 1);


	t = time(NULL);
	local = localtime(&t);


	if(strcmp(t1, "91 2d 0c 26") == 0){
		printf("Access Granted %s\n", asctime(local));
		fflush(stdout);
		sleep(1);
	} else {
		printf("Access Denied %s\n", asctime(local));
	}
    return 0;
}