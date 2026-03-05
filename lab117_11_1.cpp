#include <iostream>
#include <cstdio>

using namespace std;

int BSRecur(int data[], int n, int find, int i, int j);
int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = { 1, 2, 3, 4, 5, 7 };
    int n = 6, find = 5;
    int pos = BinSearch(data, n, find);
    
    if (pos != -1)
        printf("Found %d at %d\n", find, pos);
    else
        printf("Not Found\n");
        
    return 0;
}

int BSRecur(int data[], int n, int find, int i, int j) {
    if (i < j) {
        int m = (i + j) / 2;
        if (data[m] < find)
            return BSRecur(data, n, find, m + 1, j);
        else
            return BSRecur(data, n, find, i, m);
    } else {
        return i;
    }
}

int BinSearch(int data[], int n, int find) {
    int i = BSRecur(data, n, find, 0, n - 1);
    if (data[i] == find)
        return i;
    else
        return -1;
}