#include <iostream>
using namespace std;

#define maxn 1001
#define maxv 1001
#define inf 0
#define init 1
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return init;
}

void Knapsack01(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    // 1. ≥ı ºªØ
    for (int i = 1; i <= V; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0] = init;

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
    cin >> V;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        v[i] = 0;
    }
    Knapsack01(n, V, w, v, dp);
    int ans = 0;
    for (int i = V; i >= 0; --i) {
        if (dp[n][i] == init) {
            ans = V - i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}