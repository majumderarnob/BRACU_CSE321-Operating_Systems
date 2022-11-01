#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 1001


int main() {
    
    char st[LENGTH];
    scanf("%s", st);
    char* left = &st[0];
    char* right;
    char* temp = &st[0];
    
    while (*temp != '\0') {
        right = temp;
        temp++;
    }
    
    int x = 1, len = (int)strlen(st);
    len = (len / 2) + 1; 
    
    for(int i=0; i<len; i++) {
        if (*left != *right) {
            printf("Not Palindrome\n");
            x--;
            break;
        }
        left++;
        right--;
    }

    if (x) {
        printf("Palindrome\n");
    }
    
    return 0;
}
