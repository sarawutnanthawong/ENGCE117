#include <stdio.h>

void reverse( char str1[], char str2[] );

int main() {
    char text[100];
    char out[100];

    printf("Input: ");
    fgets(text, sizeof(text), stdin);
    
    int i = 0;
    while(text[i] != '\0') {
        if(text[i] == '\n') {
            text[i] = '\0';
            break;
        }
        i++;
    }

    reverse(text, out);
    printf("Output: %s\n", out);

    return 0;
}

void reverse( char str1[], char str2[] )
{
    int len = 0;

    
    while (str1[len] != '\0')
        len++;

    
    for (int i = 0; i < len; i++)
        str2[i] = str1[len - 1 - i];

    str2[len] = '\0';
}