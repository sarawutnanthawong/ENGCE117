#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student *child) {
    if (child->sex == 'M' || child->sex == 'm') {
        child->gpa = child->gpa * 1.10;
    } else if (child->sex == 'F' || child->sex == 'f') {
        child->gpa = child->gpa * 1.20;
    }
}

int main() {
    struct student aboy;

    printf("Enter sex (M/F): ");
    scanf(" %c", &aboy.sex);

    printf("Enter current GPA: ");
    scanf("%f", &aboy.gpa);

    upgrade(&aboy); 

    printf("--- Result ---\n");
    printf("Sex: %c\n", aboy.sex);
    printf("Upgraded GPA: %.2f\n", aboy.gpa); 

    return 0;
}