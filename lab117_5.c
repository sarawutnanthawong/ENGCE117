#include <stdio.h>
#include <stdlib.h>

int* GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    data = GetMatrix(&m, &n);

    printf("\nMatrix (%d x %d):\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    free(data);
    return 0;
}

int* GetMatrix(int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);

    printf("Enter number of columns: ");
    scanf("%d", col);

    int *value = (int*) malloc((*row) * (*col) * sizeof(int));

    printf("Enter matrix elements (%d x %d):\n", *row, *col);
    for(int i = 0; i < *row; i++) {
        for(int j = 0; j < *col; j++) {
            scanf("%d", &value[i * (*col) + j]);
        }
    }

    return value;
}
