#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


#define ll long long 
#define LENGTH 1000


int main(int argc, char *argv[]){
    printf("It is in oddeven.c\n");

    ll n = argc-1;
    ll arr[n];
    for(ll i=1; i<argc; i++){
        arr[i-1] = atoll(argv[i]);
    }

    for(ll i=0; i<n; i++){
        printf("%lld is an %s number\n",arr[i], (arr[i]%2)?"odd":"even");
    }
}