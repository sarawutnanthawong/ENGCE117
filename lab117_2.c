#include <stdio.h>


void GetSet(int *data[], int *num);

int main() {

    int *data, num;
    
    GetSet(&data, &num);
    
    return 0;
}

void GetSet(int *data[], int *num) {

    printf("What num do u want? : ");
    scanf("%d", num);


    *data = new int[*num]; 

    for (int i = 0; i < *num; i++) {
        printf("Enter ur num %d: ", i + 1);
        

        scanf("%d", &(*data)[i]); 
    }

    printf("You entered:\n");
    for (int i = 0; i < *num; i++) {
        printf("number ur %d: %d\n", i + 1, (*data)[i]);
    }
    
    delete[] *data;
}