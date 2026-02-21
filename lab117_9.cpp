#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, **now;
public:
    LinkedList() {
        start = NULL;
        now = &start;
    }

    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new struct studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = NULL;

        struct studentNode **curr = &start;
        while (*curr != NULL) {
            curr = &((*curr)->next);
        }
        *curr = newNode;
    }

    void DelNode() {
        if (start == NULL) return;
        struct studentNode *temp = start;
        start = start->next;
        delete temp;
    }

    void ShowAll() {
        struct studentNode *curr = start;
        int i = 0;
        while (curr != NULL) {
            printf("%d: %10s %2c %2d %4.2f\n", i++, curr->name, curr->sex, curr->age, curr->gpa);
            curr = curr->next;
        }
    }

    struct studentNode* getStart() { return start; }
};

void readfile(LinkedList *l1) {
    FILE *fp = fopen("student.dat", "rb");
    if (fp == NULL) return;

    struct studentNode temp;
    while (fread(&temp, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp) == 1) {
        l1->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }
    fclose(fp);
}

void writefile(LinkedList *l1) {
    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        printf("Can't open file!");
        return;
    }

    struct studentNode *curr = l1->getStart();
    while (curr != NULL) {
        fwrite(curr, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp);
        curr = curr->next;
    }
    fclose(fp);
}

void AddData(LinkedList *l1) {
    char name[20], sex;
    int age;
    float gpa;
    printf("Enter Name, Sex, Age and GPA: ");
    scanf("%s %c %d %f", name, &sex, &age, &gpa);
    l1->InsNode(name, age, sex, gpa);
}

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA);

    do {
        printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: AddData(&listA); break;
            case 3: listA.DelNode(); break;
            case 5: listA.ShowAll(); break;
        }
    } while (menu != 0);

    writefile(&listA);
    return 0;
}