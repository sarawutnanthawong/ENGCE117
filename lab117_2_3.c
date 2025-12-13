#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char text[100];
    char out[20][10];
    char splitter;
    int num;

    printf("Input text : ");
    fgets(text, sizeof(text), stdin);

    printf("Splitter   : ");
    scanf(" %c", &splitter);
    explode(text, splitter, out, &num);

    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("count = %d\n", num);

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0, j = 0;
    *count = 0;

    while (str1[i] != '\0' && str1[i] != '\n') {
        if (str1[i] == splitter) {
            str2[*count][j] = '\0';
            (*count)++;
            j = 0;
        } else {
            str2[*count][j] = str1[i];
            j++;
        }
        i++;
    }

    str2[*count][j] = '\0';
    (*count)++;
}