#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 1001

int main() {
    
    char st[LENGTH], fnd[] = "@sheba.xyz";
    scanf("%s", st);
    char* ptr;
    ptr = strstr(st, fnd);
    
    if (ptr) {
        printf("Email address is ok\n");
    } 
    else {
        printf("Email address is outdated\n");
    }
    return 0;
}
