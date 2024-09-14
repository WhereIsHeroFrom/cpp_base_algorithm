#include <iostream>
#include <cmath>
using namespace std;

#define maxn 1001
#define edgeType double
#define inf 1000000000

void initEdges(int n, edgeType graph[maxn][maxn]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = (i == j ? 0 : inf);
        }
    }
}

void addEdge(edgeType graph[maxn][maxn], int u, int v, edgeType w) {
    if (w < graph[u][v]) {
        graph[u][v] = w;
    }
    if (w < graph[v][u]) {
        graph[v][u] = w;
    }
}

edgeType prim(int n, edgeType graph[maxn][maxn]) {
    int visited[maxn] = { 0 };
    edgeType dist[maxn];
    edgeType sum = 0;
    for (int i = 0; i < n; ++i) {
        dist[i] = graph[0][i];
    }
    visited[0] = 1;
    while (1) {
        edgeType minDist = inf;
        int minIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            break;
        }
        sum += minDist;
        visited[minIndex] = 1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && graph[minIndex][i] < dist[i]) {
                dist[i] = graph[minIndex][i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return -1;
        }
    }
    return sum;
}

edgeType graph[maxn][maxn];

int SQR(int x) {
    return x * x;
}
int n;
int x[maxn], y[maxn], h[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
    }
    initEdges(n, graph);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edgeType w = sqrt(SQR(x[i] - x[j]) + SQR(y[i] - y[j])) + SQR(h[i] - h[j]);
            addEdge(graph, i, j, w);
        }
    }
    printf("%.2lf\n", prim(n, graph));
    return 0;
}