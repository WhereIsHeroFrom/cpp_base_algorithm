#include <iostream>
using namespace std;

#define maxn 2022
#define edgeType int
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

int main()
{
    initEdges(2021, graph);
    for (int i = 1; i <= 2021; ++i) {
        for (int j = i + 1; j <= 2021; ++j) {
            int u = i, v = j;
            edgeType w = 0;
            while (u || v) {
                if (u % 10 != v % 10) {
                    w += u % 10 + v % 10;
                }
                u /= 10;
                v /= 10;
            }
            addEdge(graph, i - 1, j - 1, w);
        }
    }
    cout << prim(2021, graph) << endl;

    return 0;
}