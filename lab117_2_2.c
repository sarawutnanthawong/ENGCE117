#include <stdio.h>

char* reverse(char str1[]);

int main() {
    char text[200];
    char *out;

    printf("Input: ");
    fgets(text, sizeof(text), stdin);

    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
        i++;
    }

    out = reverse(text);

    printf("Output: %s\n", out);

    return 0;
}

char* reverse(char str1[]) {
    static char out[100];
    int len = 0;

    while (str1[len] != '\0')
        len++;

    // กลับข้อความ
    for (int i = 0; i < len; i++)
        out[i] = str1[len - 1 - i];

    out[len] = '\0';

    return out;
}