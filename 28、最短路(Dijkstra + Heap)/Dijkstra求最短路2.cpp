#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define inf 1000000001
#define maxn 100001
#define ValueType int

struct Dist {
    int v;
    ValueType w;
    Dist() {}
    Dist(int _v, ValueType _w) : v(_v), w(_w) {}
    bool operator < (const Dist& d) const {
        return w > d.w;        // 小顶堆
    }
};
typedef priority_queue<Dist> Heap;

void addEdge(vector<Dist>* edges, int u, int v, ValueType w) {
    edges[u].push_back(Dist(v, w));
}

void dijkstraInit(int n, int st, Heap& heap, bool* visited, ValueType* dist) {
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
        visited[i] = false;
    }
    dist[st] = 0;
    heap.push(Dist(st, 0));
}

int dijkstraFindMin(Heap& heap) {
    Dist s = heap.top();
    heap.pop();
    return s.v;
}

void dijkstraUpdate(int u, vector<Dist>* edges, Heap& heap, bool* visited, ValueType* d) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].v;
        ValueType w = edges[u][i].w;
        if (d[u] + w < d[v]) {
            d[v] = d[u] + w;
            heap.push(Dist(v, d[v]));
        }
    }
}

void DijkstraHeap(int n, int st, vector<Dist>* edges, ValueType* d) {
    Heap heap;
    bool visited[maxn] = { false };
    dijkstraInit(n, st, heap, visited, d);
    while (!heap.empty()) {
        int u = dijkstraFindMin(heap);
        dijkstraUpdate(u, edges, heap, visited, d);
    }
}

vector<Dist> edges[maxn];
ValueType d[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        addEdge(edges, u, v, w);
    }
    DijkstraHeap(n, 0, edges, d);
    if (d[n - 1] == inf) {
        cout << -1 << endl;
    }
    else {
        cout << d[n - 1] << endl;
    }

    // 请在此输入您的代码
    return 0;
}