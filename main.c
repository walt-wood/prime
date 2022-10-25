#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
void copyString(char inputString[], char * destinationString);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

/* Place your function definitions here. Be sure to include the definitions for 
   createStudent(), append(), printStudents() as well as any other functions you 
   created for the previous tasks. */

struct student * createStudent(char studentName[], int age) {
    struct student * ptr;
    ptr = (struct student *) malloc(sizeof(struct student));
    copyString(studentName, ptr->name);
    ptr->age = age;
    ptr->next = NULL;

    return ptr;
}

void copyString(char inputString[], char * destinationString) {

    int i = 0;
    for(i = 0; inputString[i] != '\0'; i++) {
        destinationString[i] = inputString[i];
    }
    destinationString[i] = '\0';

}

struct student * append(struct student * currentEnd, struct student * newStudent) {

    currentEnd->next = newStudent;    
    return currentEnd->next;
}

void printStudents(struct student *start) {
    struct student * ptr = start;

    while (ptr != NULL) {
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}

void freeStudents(struct student *start) {
    struct student *ptr = start;
    struct student *temp;

    while( ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}