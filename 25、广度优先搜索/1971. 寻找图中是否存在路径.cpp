#define maxn 200001

class Solution {
    vector< vector<int> > edges;
    // edges[i][j];

    void initEdges(int n) {
        edges.clear();
        for (int i = 0; i < n; ++i) {
            edges.push_back({});
        }
        // edges[i] kong
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
    }

    void bfs(int n, int s, bool visited[maxn]) {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < edges[u].size(); ++i) {
                int v = edges[u][i];
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }


public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        initEdges(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            addEdge(u, v);
            addEdge(v, u);
        }
        bool v[maxn];
        bfs(n, source, v);
        return v[destination];
    }
};