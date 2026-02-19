#include <iostream>
#include <cstring>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {
protected:
    studentNode *start, *now;

public:
    LinkedList() {
        start = NULL;
        now = NULL;
    }

    ~LinkedList() {
        studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        studentNode *temp = new studentNode;
        strcpy(temp->name, n);
        temp->age = a;
        temp->sex = s;
        temp->gpa = g;
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
            now = temp;
        } else {
            studentNode *p = start;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }

    void DelNode() {
        if (start == NULL || now == NULL)
            return;

        if (now == start) {
            start = start->next;
            delete now;
            now = start;
        } else {
            studentNode *p = start;
            while (p->next != now)
                p = p->next;
            p->next = now->next;
            delete now;
            now = p->next;
        }
    }

    void GoNext() {
        if (now != NULL && now->next != NULL)
            now = now->next;
    }

    virtual void ShowNode() {
        if (now != NULL)
            printf("%s %d %c %.2f\n", now->name, now->age, now->sex, now->gpa);
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = start;
    }

    virtual void ShowNode() {
        if (start != NULL && now != NULL)
            printf("%s %s\n", now->name, start->name);
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode((char*)"one", 1, 'A', 1.1);
    listA.InsNode((char*)"two", 2, 'B', 2.2);
    listA.InsNode((char*)"three", 3, 'C', 3.3);

    listA.GoNext();
    listA.ShowNode();

    listB.InsNode((char*)"four", 4, 'D', 4.4);
    listB.InsNode((char*)"five", 5, 'E', 5.5);
    listB.InsNode((char*)"six", 6, 'F', 6.6);

    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
