#define maxn 1001

class Solution {
    vector<vector<int>> edges;

    void initEdges(int n) {
        edges.clear();
        for (int i = 0; i < n; ++i) {
            edges.push_back({});
        }
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
    }

    void bfs(int n, int s, bool visited[maxn]) {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < edges[u].size(); ++i) {
                int v = edges[u][i];
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        initEdges(n);
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                addEdge(i, rooms[i][j]);
            }
        }
        bool visited[maxn];
        bfs(n, 0, visited);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};