#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printList(int, int *);
short checkPrime(int, int *);

int main(int argc, char *argv[]) {

    int ceil = (argc >= 2) ? atoi(argv[1]) : 5000;
    int i = 0, j = 0;
    short isPrime = 0;
    int arrLen = (ceil > 17) ? (1.25506 * (ceil / log(ceil))) : ( ceil / log(ceil) );// ceil / 4;
    
    int *arr = (int *) malloc(sizeof(int) * arrLen + 1);

    for(int k = 2; k <= ceil; k++) {        
        i = k / 2;

        isPrime = checkPrime(k, &i);

        if(isPrime == 1) {
            arr[j] = k;
            j++;
        }
              
    }

    printList(arrLen, arr);
    return 0;
}

void printList(int len, int *arr) {

    for(int i = 0; i < len; i++) {
        if(arr[i]) printf("%5d ", arr[i]);
    }
}

short checkPrime(int ceil, int *i) {

    if(*i == 1) return 1;
    else if(ceil % *i == 0) return 0;
    else {        
        (*i)--;
        checkPrime(ceil, i);
    }
}