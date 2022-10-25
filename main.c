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
void add(struct node *, struct node *);

int main(int argc, char *argv[]) {

    // int ceil = (argc > 0) ? (int) argv[0] : 5000;
    struct node *start, *end, *newNode;
    start = createNode(1);
    end = start;
    newNode = createNode(2);
    end = append(end, newNode);
    newNode = createNode(3);
    end = append(end, newNode);

    struct node *s2, *newN2;

    s2 = createNode(4);
    newN2 = createNode(5);
    add(s2, newN2);
    
    add(s2, createNode(6));
    
    print(start);
    printf("\n");
    print(s2);

    freeList(start);
    freeList(s2);

    return 0;
}

void print(struct node *start) {
    struct node *ptr = start;
    while (ptr) {
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

void add(struct node *start, struct node *newNode) {

    struct node *ptr = start;

    while (ptr->next)
    {
        ptr = ptr->next;
    }
    
    ptr->next = newNode;

}

struct node *append(struct node *currentEnd, struct node *newNode) {

    currentEnd->next = newNode;
    return currentEnd->next;
}

void freeList(struct node *start) {

    struct node *ptr = start;
    struct node *temp;

    while(ptr) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

