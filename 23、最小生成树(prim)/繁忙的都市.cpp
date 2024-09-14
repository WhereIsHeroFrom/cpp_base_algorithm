#include <iostream>
using namespace std;

#define maxn 301
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

#define maxm 100001
edgeType graph[maxn][maxn];
int n, m;
int u[maxm], v[maxm], c[maxm];

int check(int max) {
    initEdges(n, graph);
    for (int i = 0; i < m; ++i) {
        if (c[i] <= max) {
            addEdge(graph, u[i] - 1, v[i] - 1, c[i]);
        }
    }
    return prim(n, graph) >= 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> c[i];
    }
    int l = 0, r = 10000;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << n - 1 << ' ' << ans << endl;

    return 0;
}