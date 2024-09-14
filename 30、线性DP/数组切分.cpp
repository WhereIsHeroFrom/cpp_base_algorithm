#include <iostream>
using namespace std;

#define maxn 10001
#define mod 1000000007
int dp[maxn];
int a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int mmax = 0;
        int mmin = 10000000;
        for (int j = i; j >= 1; --j) {
            mmax = max(mmax, a[j]);
            mmin = min(mmin, a[j]);
            if (mmax - mmin == i - j) {
                dp[i] += dp[j - 1];
                if (dp[i] >= mod) {
                    dp[i] -= mod;
                }
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}