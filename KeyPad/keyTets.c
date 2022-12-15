#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int counter = 0;
    char resBuff[5];
    char x;

    char result[10];
    //while(1){
        while(counter < 5){
            scanf(" %c", &x);
            resBuff[counter] = x;

            counter++;
        }
    sprintf(result, "%c %c %c %c %c", resBuff[0], resBuff[1], resBuff[2], resBuff[3], resBuff[4]);
    printf("%s", result);

    if(strcmp(result, "1 2 2 3 5") == 0){
        printf("Access Granted");
    }else {
        printf("Access Denied");
    }
    
 //   }
    return 0;
}