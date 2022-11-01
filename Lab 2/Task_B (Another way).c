#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1001

int main() {
    FILE * pointer1_forWrite;
    pointer1_forWrite = fopen("input.txt", "w");
    fprintf(pointer1_forWrite, "I                      love        Python   Programming");
    fclose(pointer1_forWrite);

    FILE * pointer1_forRead;
    pointer1_forRead = fopen("input.txt", "r");
    
    FILE * pointer2_forWrite;
    pointer2_forWrite = fopen("output.txt", "w");
    char s[LENGTH];
    
    while (!feof(pointer1_forRead)) {
        fgets(s, LENGTH, pointer1_forRead);
        int x = (int)strlen(s);
        int spc = 0;
        char espc = ' ';
        for(int i=0; i < x; i++) {
            if (s[i] != ' ') {
                fputc(s[i], pointer2_forWrite);
                if (spc == 1) {
                    spc--;
                }
            }
            else {
                if (spc == 0) {
                    fputc(espc, pointer2_forWrite);
                    spc++;
                }
                else {
                    continue;
                }
            }
        }
    }
    
    fclose(pointer1_forRead);
    fclose(pointer2_forWrite);
    
    return 0;
}
