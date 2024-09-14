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
    const int n = 6;
    const int m = 9;
    int edges[m][3] = {
        {0, 1, 1},
        {0, 2, 4},
        {0, 3, 10},
        {1, 2, 2},
        {2, 3, 5},
        {2, 4, 1},
        {2, 5, 3},
        {4, 5, 1},
        {5, 3, 1},
    };

    // 初始化
    initEdges(n, graph);

    // 建图
    for (int i = 0; i < m; ++i) {
        addEdge(graph, edges[i][0], edges[i][1], edges[i][2]);
    }
    // prim
    int dist[maxn];
    cout << "最小生成树的长度为：" << prim(n, graph) << endl;

    return 0;
}