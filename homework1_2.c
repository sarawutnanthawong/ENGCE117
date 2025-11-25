#include <stdio.h>

int main() {
    int score;
    
    
    if (scanf("%d", &score) != 1) {
        return 1; 
    }
    
    if (score >= 80) {
        printf("A");
    } else if (score >= 75){
        printf("B+");
    } else if (score >= 70){
        printf("B");
    } else if (score >= 65){
        printf("C+");
    } else if (score >= 60){
        printf("C");
    } else if (score >= 55){
        printf("D+");
    } else if (score >= 50){
        printf("D");
    } else {
        printf("F");
    }

    return 0;
}