#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 1001

int main() {
    char st[LENGTH], ch;
    printf("Enter your password: ");
    scanf("%s", st);
    int x = (int)strlen(st);
    int Low_case = 0, up_case = 0, dgt = 0, spc = 0;
    int initial_val = 0;
    for(int i=0; i < x; i++) {
        ch = st[i];
        if (ch >= 'a' && ch <= 'z' && Low_case == 0)
            Low_case++;
        if (ch >= 'A' && ch <= 'Z' && up_case == 0)
            up_case++;
        if (ch >= '0' && ch <= '9' && dgt == 0)
            dgt++;
        if ((ch == '_' || ch == '$' || ch == '#' || ch == '@') && spc == 0)
            spc++;
        
        if (Low_case == 1 & up_case == 1 & dgt == 1 & spc == 1)
            break;
    }
    
    if (Low_case == 1 & up_case == 1 & dgt == 1 & spc == 1) {
        printf("OK\n");
    }
    
    if (Low_case == 0) {
        initial_val = 1; 
        printf("Lowercase character missing");
    }
    if (up_case == 0) {
        if (initial_val)
            printf(", ");
        printf("Uppercase character missing");
        initial_val = 1;
    }
    if (dgt == 0) {
        if (initial_val)
            printf(", ");
        printf("Digit missing");
        initial_val = 1;
    }
    if (spc == 0) {
        if (initial_val)
            printf(", ");
        printf("Special character missing");
    }
    
    return 0;
}
