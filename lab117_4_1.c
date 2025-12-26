#include <stdio.h>

void go( int **p, int *z);

void go( int **p, int *z){
    *p = z;
}

int main() {
    int *a, b =10, c = 20;
    go( &a, &b ) ;
    printf( "Point to b -> value: %d, address in a: %p, address of a: %p\n", *a, a, &a ) ;
    go( &a, &c ) ;
    printf( "Point to c -> value: %d, address in a: %p, address of a: %p\n", *a, a, &a ) ;
    return 0 ;
}