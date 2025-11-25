#include <stdio.h>

int main() {
    int score;
    
    printf("Enter your Grade :");
    if (scanf("%d", &score) != 1) {
        return 1; 
    }
    
    if (score >= 80) {
        printf("your grade is A good job");
    } else if (score >= 75){
        printf("your grade is B+ keep trying");
    } else if (score >= 70){
        printf("your grade is B not bad");
    } else if (score >= 65){
        printf("your grade is C+ next time, try again");
    } else if (score >= 60){
        printf("your grade Grade is C wow");
    } else if (score >= 55){
        printf("your grade is D+ figthing");
    } else if (score >= 50){
        printf("your grade is D well well well");
    } else {
        printf("your grade is F hehe");
    }

    return 0;
}