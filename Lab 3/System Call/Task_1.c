#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define LENGTH 1000

int main(int argc, char **argv){
    if (argc>=1){
        printf("Do you want to open a file and write in it? [Y/n]\n");
        char x;
        scanf("%c ",&x);
        char q[] = "-1\n";
        if (x=='Y' || x=='y'){
            FILE * fpointer; 
            fpointer = fopen("default.txt", "w");
            char inp[LENGTH];
            fgets(inp,LENGTH,stdin);
            while (strcmp(inp,q) != 0){
                fputs(inp,fpointer);
                fgets(inp,LENGTH,stdin);
            }
            fclose(fpointer);
        }
    }
    return 0;
}
