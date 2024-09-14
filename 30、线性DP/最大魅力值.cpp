#include <iostream>
using namespace std;

#define maxn 101
#define inf -10000000
int dp[maxn][maxn];
int a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0;

    dp[1][0] = 0;
    dp[1][1] = a[1];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(a[i] + dp[i - 2][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[n][n / 2] << endl;

    return 0;
}