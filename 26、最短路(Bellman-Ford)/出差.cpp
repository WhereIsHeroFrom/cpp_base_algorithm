#include <iostream>
using namespace std;

#define maxn 1001
#define maxm 20001
#define eType int
#define inf 1000000000

struct EDGE {
    int u, v;
    eType w;
};

int doRelax(int m, EDGE* edges, eType* dist) {
    int isRelax = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        eType w = edges[i].w;
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            isRelax = 1;
        }
    }
    return isRelax;
}

int bellman(int n, int m, EDGE* edges, int s, eType* dist) {
    for (int i = 0; i < n; ++i) {
        dist[i] = (i == s ? 0 : inf);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (!doRelax(m, edges, dist)) {
            return 0;
        }
    }
    return doRelax(m, edges, dist);
}

int n, e, m;
EDGE edges[maxm];
eType dist[maxn];
int c[maxn];

int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    c[n - 1] = 0;
    m = 0;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[m].u = u - 1;
        edges[m].v = v - 1;
        edges[m].w = w + c[v - 1];
        m++;

        edges[m].u = v - 1;
        edges[m].v = u - 1;
        edges[m].w = w + c[u - 1];
        m++;
    }
    bellman(n, m, edges, 0, dist);
    cout << dist[n - 1] << endl;

    return 0;
}