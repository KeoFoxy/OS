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





    //Code below runs only if programm receives as 
    //arguments -q mode and namedPipe char*


    if((argc > 2) && (strcmp(argv[1], "-q") == 0)){
    
    int fd;
    char *fifo;
    char result[255];

    //Check for external arguments
    //take second argument if you are using -q mode

    fifo = argv[2];
    
   // printf("%d\n", argc);
   // printf("%s", fifo);

    //printf("\n");

    mkfifo(fifo, 0666); //Create names pipe with given name via run arguments

    sprintf(result, "%s", "Access Granted"); //just for check if code is working properly

    //printf("%s", result);
   // printf("\n");

    fd = open(fifo, O_RDWR);
    write(fd, result, strlen(result) + 1);

    //close(fd);
	t = time(NULL);
	local = localtime(&t);


	if(strcmp(t1, "91 2d 0c 26") == 0){
		printf("Access Granted %s\n", asctime(local));
		fflush(stdout);
		//sleep(1);
	} else {
		printf("Access Denied %s\n", asctime(local));
	}

    }

    return 0;
}