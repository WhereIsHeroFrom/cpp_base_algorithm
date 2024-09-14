#define maxn 200
#define edgeType long long
#define inf ((edgeType)1000000000 * 1000)
#define mod 1000000007

class Solution {
    edgeType f[maxn][maxn];
    edgeType c[maxn][maxn];

    void initEdges(int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    f[i][j] = 0;
                    c[i][j] = 1;
                }
                else {
                    f[i][j] = inf;
                    c[i][j] = 0;
                }
            }
        }
    }

    void addEdge(int u, int v, edgeType w) {
        if (w < f[u][v]) {
            f[u][v] = w;
            c[u][v] = 1;
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
                        c[i][j] = c[i][k] * c[k][j] % mod;
                    }
                    else if (f[i][k] + f[k][j] == f[i][j]) {
                        c[i][j] += c[i][k] * c[k][j] % mod;
                        if (c[i][j] >= mod) {
                            c[i][j] %= mod;
                        }
                    }
                }
            }
        }
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        initEdges(n);
        for (int i = 0; i < roads.size(); ++i) {
            int u = roads[i][0];
            int v = roads[i][1];
            edgeType w = roads[i][2];
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        FloyedWarshall(n);
        return c[0][n - 1];
    }
};