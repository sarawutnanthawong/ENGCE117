#include <iostream>
#include <cstdio>

using namespace std;

int* dijkstra(int* L, int n) {
    int* D = new int[n];
    bool* visited = new bool[n];
    
    for (int i = 0; i < n; i++) {
        D[i] = L[0 * n + i];
        visited[i] = false;
    }
    
    visited[0] = true;

    for (int count = 0; count < n - 2; count++) {
        int v = -1;
        int min_dist = 999999;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && D[i] != -1 && D[i] < min_dist) {
                min_dist = D[i];
                v = i;
            }
        }
        
        if (v == -1) break;
        visited[v] = true;
        
        for (int w = 0; w < n; w++) {
            if (!visited[w] && L[v * n + w] != -1) {
                int new_dist = D[v] + L[v * n + w];
                if (D[w] == -1 || new_dist < D[w]) {
                    D[w] = new_dist;
                }
            }
        }
    }
    return D;
}

int main() {
    int n = 5;
    int* g = new int[n * n];
    for (int i = 0; i < n * n; i++) g[i] = -1;
    
    g[0 * n + 1] = 100;
    g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;
    g[0 * n + 4] = 10;
    g[1 * n + 2] = 25;
    g[3 * n + 1] = 20;
    g[3 * n + 2] = 40;
    g[4 * n + 3] = 10;

    int* d = dijkstra(g, n);
    for (int i = 1; i < n; i++) printf("%d ", d[i]);
    
    return 0;
}