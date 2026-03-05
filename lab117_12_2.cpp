#include <iostream>
#include <cstdio>

using namespace std;

int* knapsackGD(int* w, int* v, int n, int wx) {
    int* x = new int[n];
    double* ratio = new double[n];
    bool* selected = new bool[n];
    
    for (int i = 0; i < n; i++) {
        x[i] = 0;
        ratio[i] = (double)v[i] / w[i];
        selected[i] = false;
    }
    
    int current_weight = 0;
    
    for (int count = 0; count < n; count++) {
        int best_idx = -1;
        double max_ratio = -1.0;
        
        for (int i = 0; i < n; i++) {
            if (!selected[i] && ratio[i] > max_ratio) {
                max_ratio = ratio[i];
                best_idx = i;
            }
        }
        
        if (best_idx == -1) break;
        selected[best_idx] = true;
        
        if (current_weight + w[best_idx] <= wx) {
            x[best_idx] = 1;
            current_weight += w[best_idx];
        }
    }
    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int* x = knapsackGD(w, v, n, wx);
    for (int i = 0; i < n; i++) printf("%d", x[i]);
    return 0;
}