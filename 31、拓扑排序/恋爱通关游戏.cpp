#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxn 200005
#define eType vector<int>

void initEdges(int n, vector<eType> edges[maxn]) {
    for (int i = 0; i < n; ++i) {
        edges[i].clear();
    }
}

void addEdge(vector<eType> edges[maxn], int u, int v, int w) {
    edges[u].push_back({ v, w });
}

bool topoSort(int n, vector<eType> edges[maxn], vector<int>& ans) {
    vector<int> deg;
    queue<int> q;
    ans.clear();
    for (int i = 0; i < n; ++i) {
        deg.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edges[i].size(); ++j) {
            int v = edges[i][j][0];
            ++deg[v];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i][0];
            --deg[v];
            if (!deg[v]) {
                q.push(v);
            }
        }
    }
    return ans.size() == n;
}

vector<eType> edges[maxn];
long long dp[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        --A, --B;
        addEdge(edges, A, B, C);
    }
    vector<int> ans;
    int ret = 0;
    topoSort(n, edges, ans);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = -1e9;
    }
    for (int i = 0; i < ans.size(); ++i) {
        int u = ans[i];
        for (int j = 0; j < edges[u].size(); ++j) {
            int v = edges[u][j][0];
            int w = edges[u][j][1];
            dp[v] = max(dp[v], dp[u] + w);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i] >= 100 && edges[i].empty()) {
            ++ret;
        }
    }

    cout << ret << endl;

    return 0;
}