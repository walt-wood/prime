#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void print(struct node *);
struct node *createNode(int );
struct node *append(struct node *, struct node *);
void freeList(struct node *);

int main(int argc, char *argv[]) {

    // int ceil = (argc > 0) ? (int) argv[0] : 5000;
    struct node *start, *end, *newNode;
    start = createNode(1);
    end = start;
    newNode = createNode(2);
    end = append(end, newNode);
    newNode = createNode(3);
    end = append(end, newNode);

    
    print(start);

    freeList(start);
    return 0;
}

void print(struct node *start) {
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->num);
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

struct node *append(struct node *currentEnd, struct node *newNode) {

    currentEnd->next = newNode;
    return currentEnd->next;
}

void freeList(struct node *start) {

    struct node *ptr = start;
    struct node *temp;

    while( ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

