#include <stdio.h>

int main() {
    int N, i;
    
    
    if (scanf("%d", &N) != 1) {
        return 1; 
    }
    
    if (N <= 0) {
        printf("Error");
    } else {
        for (i = 0 ; i < N ; i++);
            printf("Heelo loop!\n");
    }
    

    return 0;
}