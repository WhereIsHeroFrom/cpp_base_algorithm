long long point[402];
int pointSize;
#define base 100001

int findPoint(int x, int y) {
    long long p = (long long)x * base + y;
    for (int i = 0; i < pointSize; ++i) {
        if (p == point[i]) {
            return i;
        }
    }
    point[pointSize++] = p;
    return pointSize - 1;
}

#define maxn 402
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
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        pointSize = 0;
        initEdges(maxn);
        int s = findPoint(start[0], start[1]);
        int t = findPoint(target[0], target[1]);
        for (int i = 0; i < specialRoads.size(); ++i) {
            int u = findPoint(specialRoads[i][0], specialRoads[i][1]);
            int v = findPoint(specialRoads[i][2], specialRoads[i][3]);
            edgeType w = specialRoads[i][4];
            addEdge(u, v, w);
        }
        for (int i = 0; i < pointSize; ++i) {
            int x1 = point[i] / base;
            int y1 = point[i] % base;
            for (int j = 0; j < pointSize; ++j) {
                int x2 = point[j] / base;
                int y2 = point[j] % base;
                int w = abs(x1 - x2) + abs(y1 - y2);
                addEdge(i, j, w);
            }
        }
        edgeType dist[maxn];
        dijkstra(pointSize, s, dist);
        return dist[t];
    }
};