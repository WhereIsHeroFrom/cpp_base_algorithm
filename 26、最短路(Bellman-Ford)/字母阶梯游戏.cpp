#include <iostream>
#include <cstring>
using namespace std;

#define maxn 501
#define maxm 250001
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
eType dist[maxn];

int calcEdge(char* a, char* b) {
    int ans = 0;
    for (int i = 0; a[i]; ++i) {
        if (a[i] != b[i]) {
            ++ans;
        }
        if (ans > 1) {
            return 0;
        }
    }
    return 1;
}

char str[maxn][maxn];
char st[maxn], en[maxn];



int main()
{
    cin >> n;
    m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (calcEdge(str[i], str[j])) {
                edges[m].u = i;
                edges[m].v = j;
                edges[m].w = 1;
                m++;

                edges[m].u = j;
                edges[m].v = i;
                edges[m].w = 1;
                m++;
            }
        }
    }
    cin >> st;
    cin >> en;
    int s, d;
    for (int i = 0; i < n; ++i) {
        if (!strcmp(st, str[i])) s = i;
        if (!strcmp(en, str[i])) d = i;
    }
    bellman(n, m, edges, s, dist);
    if (dist[d] == inf) dist[d] = -1;
    cout << dist[d] << endl;
    return 0;
}