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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        initEdges(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            edgeType w = edges[i][2];
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int retCnt = 100000000;
        int retIdx = -1;
        for (int i = n - 1; i >= 0; --i) {
            edgeType dist[maxn];
            dijkstra(n, i, dist);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            if (cnt < retCnt) {
                retCnt = cnt;
                retIdx = i;
            }
        }

        return retIdx;
    }
};