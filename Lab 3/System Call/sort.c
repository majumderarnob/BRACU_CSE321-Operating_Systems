#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


#define ll long long 
#define LENGTH 1000

void swap(ll *x, ll *y){
    ll temp = *x; 
    *x = *y;    
    *y = temp; 
}

int main(int argc, char *argv[]){
    printf("This is in sort.c\n");

    ll n = argc-1;
    ll arr[n];
    for(ll i=1; i<argc; i++){
        arr[i-1] = atoll(argv[i]);
    }
    for(ll i=0; i<n-1; i++){
        for(ll j=0; j<n-1-i; j++){
            if (arr[j] < arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("Sorted: ");
    for(ll i=0; i<n; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
}