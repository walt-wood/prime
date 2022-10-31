#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma region Iterative

void printList(int);
int isPrime(int);

int main(int argc, char *argv[]) {

    int ceil = (argc >= 2) ? atoi(argv[1]) : 5000;

    printList(ceil);

    return 0;
}


void printList(int n) {

    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) printf("%5d ", i);
    }
}

int isPrime(int n) {

    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0 || n %3 == 0) return 0;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    }

    return 1;
}

#pragma endregion Iterative