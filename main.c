#include <stdio.h>
#include <stdlib.h>

struct node
{    
    unsigned int num;
    struct node *next;
};

void printList(struct node *);
struct node *createNode(int);
void freeList(struct node *);
void add(struct node **, int);
short checkPrime(int, int *);

int main(int argc, char *argv[]) {    // 
    
    int ceil = (argc >= 2) ? atoi(argv[1]) : 5000;
    int i = 0;
    int isPrime = 0;

    struct node *head = NULL;

    for(int k = 2; k <= ceil; k++) {        
        i = k / 2;

        isPrime = checkPrime(k, &i);

        if(isPrime == 1) {
            add(&head, k);
        }        
    }

    printList(head);
    freeList(head);

    return 0;
}

void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%4d ", ptr->num);
        ptr = ptr->next;
    }
}

struct node *createNode(int num) {

    struct node *ptr;
    ptr = (struct node *) malloc(sizeof(struct node));

    ptr->num = num;
    ptr->next = NULL;

    return ptr;
}

void add(struct node **head, int num) {

    struct node *newNode = createNode(num);

    if(*head == NULL) {
        *head = newNode;
    } else {

        struct node *ptr = *head;

        while (ptr->next)
        {
            ptr = ptr->next;
        } 

        ptr->next = newNode;
    }

}

void freeList(struct node *head) {

    struct node *ptr = head;
    struct node *temp;

    while(ptr) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
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

