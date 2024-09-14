#define maxn 100001

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
    int reachableNodes(int n, vector<vector<int>>& e, vector<int>& restricted) {
        initEdges(n);
        int hash[maxn];
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < restricted.size(); ++i) {
            hash[restricted[i]] = 1;
        }
        for (int i = 0; i < e.size(); ++i) {
            int u = e[i][0];
            int v = e[i][1];
            if (hash[u] + hash[v] == 0) {
                addEdge(u, v);
                addEdge(v, u);
            }
        }
        bool v[maxn];
        bfs(n, 0, v);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                ++ans;
            }
        }
        return ans;
    }
};