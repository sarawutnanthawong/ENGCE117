#include <stdio.h>

void GetMatrix(int value[], int *row, int *col);

int main() {
    int data[100], m, n;

    GetMatrix(data, &m, &n);

    printf("\nMatrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}

void GetMatrix(int value[], int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);

    printf("Enter number of columns: ");
    scanf("%d", col);

    printf("Enter matrix elements (%d x %d):\n", *row, *col);

    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            scanf("%d", &value[i * (*col) + j]);
        }
    }
}
