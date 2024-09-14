#include <iostream>
#include <vector>
using namespace std;

#define maxn 101
#define edgeType int
#define inf INT_MAX

edgeType graph[maxn][maxn];

// 初始化邻接矩阵
void initEdges(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = inf;
        }
    }
}

// 加边
void addEdge(int u, int v, edgeType w) {
    if (graph[u][v] == inf || w < graph[u][v]) {
        graph[u][v] = w;
    }
}

// Dijkstra 框架代码
void dijkstra(int n, int s, edgeType dist[maxn]) {
    bool visited[maxn];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        dist[i] = inf;
    }
    dist[s] = 0;

    while (1) {
        edgeType minDist = inf;
        int minIndex;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            if (minDist == inf || dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minDist == inf) {
            break;
        }
        visited[minIndex] = true;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            edgeType dis = graph[minIndex][i];
            if (dis == inf) {
                continue;
            }
            if (dist[i] == inf || dist[minIndex] + dis < dist[i]) {
                dist[i] = dist[minIndex] + dis;
            }
        }
    }
}

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
    initEdges(n);

    // 建图
    for (int i = 0; i < m; ++i) {
        addEdge(edges[i][0], edges[i][1], edges[i][2]);
    }
    // dijkstra
    int dist[maxn];
    dijkstra(n, 0, dist);
    for (int i = 0; i < n; ++i) {
        cout << 0 << "到" << i << "的最短路为" << dist[i] << endl;
    }

    return 0;
}