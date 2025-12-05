#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *n) {
    int i;
    printf("Enter number : ");
    scanf("%d", n);           // รับจำนวนสมาชิก และเก็บในตัวแปร n

    int *arr = (int *)malloc((*n) * sizeof(int));   // จองหน่วยความจำ

    if (arr == NULL) {
        printf("Memory failed!\n");
        exit(1);
    }

    printf("Enter %d :\n", *n);
    for (i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;   // ส่ง pointer กลับไปให้ main
}

int main() {
    int *data, num;

    data = GetSet(&num);  

    printf("You entered:\n");
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }

    free(data);  // คืนหน่วยความจำ
    return 0;
}
