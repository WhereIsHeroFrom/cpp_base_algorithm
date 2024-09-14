#include <iostream>
using namespace std;

// dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i])
// dp[0][5] = inf
// dp[0][0] = init

#define maxn 101
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return a > b ? a : b;
}

void Knapsack01(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    // 1. ≥ı ºªØ
    for (int i = 1; i <= V; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0] = 0;

    // 2. ◊¥Ã¨◊™“∆
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= w[i]) {
                dp[i][j] = opt(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int w[maxn];
vType v[maxn];
vType dp[maxn][maxv];

int main()
{
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    Knapsack01(n, V, w, v, dp);
    vType ret = 0;
    for (int i = 0; i <= V; ++i) {
        ret = max(ret, dp[n][i]);
    }
    cout << ret << endl;

    return 0;
}