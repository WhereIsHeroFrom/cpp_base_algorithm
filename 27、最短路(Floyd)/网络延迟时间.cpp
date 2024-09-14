#define maxn 100
#define edgeType int
#define inf INT_MAX

class Solution {
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

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        initEdges(n);
        for (int i = 0; i < times.size(); ++i) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            edgeType w = times[i][2];
            addEdge(u, v, w);
        }
        k--;
        FloyedWarshall(n);
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (f[k][i] > max) {
                max = f[k][i];
            }
        }
        if (max == inf) max = -1;
        return max;
    }
};