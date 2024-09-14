#include <iostream>
using namespace std;

#define maxn 1001
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return a > b ? a : b;
}

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxv], vType dp[maxn][maxv]) {
    for (int i = 1; i <= V; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0] = init;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < w[i]; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = w[i]; j <= V; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
}

int n, V;
int w[maxn];
vType v[maxn];
vType dp[maxn][maxv];

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    KnapsackComplete(n, V, w, v, dp);
    int ans = inf;
    for (int i = 0; i <= V; ++i) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}