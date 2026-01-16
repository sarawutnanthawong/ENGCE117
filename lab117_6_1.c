#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **walk, const char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *walk, const char name[], int age, char sex, float gpa, struct studentNode **begin);
void DelNode(struct studentNode **walk, struct studentNode **begin);

int main() {
    struct studentNode *start = NULL;
    struct studentNode *now = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33, &start);
    ShowAll(start);

    DelNode(&now, &start);
    ShowAll(start);

    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **walk, const char name[], int age, char sex, float gpa) {
    struct studentNode *temp = NULL;
    while (*walk != NULL) {
        temp = *walk;
        walk = &((*walk)->next);
    }
    *walk = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
    (*walk)->next = NULL;
    (*walk)->back = temp;
    return *walk;
}

void InsNode(struct studentNode *walk, const char name[], int age, char sex, float gpa, struct studentNode **begin) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    if (walk->back != NULL) {
        newNode->next = walk;
        newNode->back = walk->back;
        walk->back->next = newNode;
        walk->back = newNode;
    } else {
        newNode->next = walk;
        newNode->back = NULL;
        walk->back = newNode;
        *begin = newNode;
    }
}

void DelNode(struct studentNode **walk, struct studentNode **begin) {
    if (*walk == NULL) return;
    
    struct studentNode *temp;
    if ((*walk)->back != NULL) {
        (*walk)->back->next = (*walk)->next;
    } else {
        *begin = (*walk)->next;
    }

    if ((*walk)->next != NULL) {
        (*walk)->next->back = (*walk)->back;
        temp = (*walk)->next;
    } else {
        temp = (*walk)->back;
    }
    free(*walk);
    *walk = temp;
}