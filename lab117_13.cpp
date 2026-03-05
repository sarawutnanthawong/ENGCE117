#include <iostream>
#include <cstdio>

using namespace std;

int knapsackBT(int* w, int* v, int n, int wx, int i, int* x) {
    int b = 0;
    for (int k = i; k < n; k++) {
        if (w[k] <= wx) {
            int y[5] = {0};
            int a = v[k] + knapsackBT(w, v, n, wx - w[k], k + 1, y);
            if (a > b) {
                b = a;
                for (int j = 0; j < n; j++) x[j] = y[j];
                x[k] = 1;
            }
        }
    }
    return b;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int x[5] = {0};
    int max_val = knapsackBT(w, v, n, wx, 0, x);
    printf("Value = %d\nBT = ", max_val);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    return 0;
}