#include <iostream>
using namespace std;

#define maxn 1001
#define maxm 100001
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


int n, m;
EDGE edges[maxm];
eType dist1[maxn], dist2[maxn];
int u[maxm], v[maxm], w[maxm];


int main()
{
    int x;
    cin >> n >> m >> x;
    --x;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i];
        --v[i];
    }
    for (int i = 0; i < m; ++i) {
        edges[i].u = u[i];
        edges[i].v = v[i];
        edges[i].w = w[i];
    }
    bellman(n, m, edges, x, dist1);
    for (int i = 0; i < m; ++i) {
        edges[i].u = v[i];
        edges[i].v = u[i];
        edges[i].w = w[i];
    }
    bellman(n, m, edges, x, dist2);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dist1[i] + dist2[i]);
    }
    cout << ret << endl;

    return 0;
}