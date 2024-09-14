#define maxn 101
#define edgeType int
#define inf INT_MAX

class Solution {
    edgeType graph[maxn][maxn];

    void initEdges(int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = inf;
            }
        }
    }

    void addEdge(int u, int v, edgeType w) {
        if (graph[u][v] == inf || w < graph[u][v]) {
            graph[u][v] = w;
        }
    }

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
                int dis = graph[minIndex][i];
                if (dis == inf) {
                    continue;
                }
                if (dist[i] == inf || dist[minIndex] + dis < dist[i]) {
                    dist[i] = dist[minIndex] + dis;
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
        edgeType dist[maxn];
        dijkstra(n, k - 1, dist);
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == inf) {
                return -1;
            }
            if (dist[i] > max) {
                max = dist[i];
            }
        }
        return max;
    }
};