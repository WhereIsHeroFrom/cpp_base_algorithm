#include <iostream>
using namespace std;
#define maxn 100
#define edgeType int
#define inf INT_MAX

edgeType f[maxn][maxn];

void initEdges(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                f[i][j] = 0;
            }
            else {
                f[i][j] = inf;
            }
        }
    }
}

void addEdge(int u, int v, edgeType w) {
    if (w < f[u][v]) {
        f[u][v] = w;
    }
}

void FloyedWarshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (f[i][k] == inf || f[k][j] == inf) {
                    continue;
                }
                if (i == k || j == k) {
                    continue;
                }
                if (f[i][k] + f[k][j] < f[i][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
}

int main()
{
    return 0;
}