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

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxv]) {
    dp[0] = init;
    for (int i = 1; i <= V; ++i) {
        dp[i] = inf;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w[i]; j <= V; ++j) {
            dp[j] = opt(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

int n, V;
int w[maxn];
vType v[maxn];
vType dp[maxv];


int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    KnapsackComplete(n, V, w, v, dp);
    int ans = inf;
    for (int i = 0; i <= V; ++i) {
        ans = opt(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}