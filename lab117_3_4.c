#include <stdio.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

void GetStudent( struct student child[][ 10 ], int *room ) {
    
    for ( int i = 0; i < *room; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            printf( "Room %d, Student %d Name: ", i + 1, j + 1 );
            scanf( "%s", child[ i ][ j ].name );
            printf( "Sex (M/F): " );
            scanf( " %c", &child[ i ][ j ].sex );
            printf( "GPA: " );
            scanf( "%f", &child[ i ][ j ].gpa );

            if ( child[ i ][ j ].sex == 'M' || child[ i ][ j ].sex == 'm' ) {
                child[ i ][ j ].gpa = child[ i ][ j ].gpa * 1.10;
            } else if ( child[ i ][ j ].sex == 'F' || child[ i ][ j ].sex == 'f' ) {
                child[ i ][ j ].gpa = child[ i ][ j ].gpa * 1.20;
            }
        }
    }
}

int main() {
    struct student children[ 20 ][ 10 ];
    int group = 1;

    GetStudent( children, &group );

    printf( "Updated GPA: %.2f\n", children[ 0 ][ 0 ].gpa );

    return 0;
}