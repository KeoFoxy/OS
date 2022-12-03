/*******************************************************************************
 * Copyright (c) 2022 Sergey Balabaev (sergei.a.balabaev@gmail.com)                     *
 *                                                                             *
 * The MIT License (MIT):                                                      *
 * Permission is hereby granted, free of charge, to any person obtaining a     *
 * copy of this software and associated documentation files (the "Software"),  *
 * to deal in the Software without restriction, including without limitation   *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell   *
 * copies of the Software, and to permit persons to whom the Software is       *
 * furnished to do so, subject to the following conditions:                    *
 * The above copyright notice and this permission notice shall be included     *
 * in all copies or substantial portions of the Software.                      *
 *                                                                             *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,             *
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR       *
 * OTHER DEALINGS IN THE SOFTWARE.                                             *
 ******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "MFRC522.h"

int debug = 0;

void help()
{
	printf("    Use this application for reading from rfid reader\n");
	printf("    execute format: ./rfid_reader [-h][-q] \n");
	printf("    return: Card ID\n");
	printf("    -h - help\n");
	printf("    -q - quiet\n");
}

int main(int argc, char *argv[])
{
	if(agrc <= 1){
		printf("     Enter arguments! ");
		printf("    -h - help\n");
		printf("    -q - quiet\n");
	}

	int quiet = 0;
	if (argc > 1) {
		if(argc < 4){
			if ((strcmp(argv[1], "-h") == 0)) {
				help();
				return 0;
			} else {
				if ((strcmp(argv[1], "-q") == 0)) {
					quiet = 1;
				}
			}
		} else {
			printf("    Too much arguments! Try less");
			printf("    -h - help\n");
			printf("    -q - quiet\n");
		}
	}

	uint8_t mode, bits;
	int status;
	unsigned char backBits;
	unsigned char *uid;
	unsigned char blockno;
	char *next;

	int fd;

	fd = open(argv[2], O_RDWR);
	//write(fd, strcmp(argv[0], "-q") , );

	MFRC522_Init(0);
	while (1) {
		while ((status = MFRC522_Request(PICC_REQIDL, &backBits)) !=
		       MI_OK)
			usleep(500);

		if (status == MI_OK)
			if (!quiet)
				//printf("Card detected\n");

		status = MFRC522_Anticoll(&uid);

		if (status == MI_OK) {
			// print UID
			if (!quiet) {
				printf("%02x %02x %02x %02x\n", uid[0], uid[1],
				       uid[2], uid[3]);
				fflush(stdout);
				break;
			}
			printf("%02x %02x %02x %02x\n", uid[0], uid[1], uid[2],
			       uid[3]);
			write(fd, )
			fflush(stdout);
			sleep(1);
		}
	}
}