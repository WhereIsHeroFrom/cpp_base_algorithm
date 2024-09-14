#include <iostream>
#include <string>
using namespace std;

int dp[10];
// dp[i] 代表以 i 结尾的最长接龙子序列

int main()
{
    int n;
    int m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string A;
        cin >> A;
        int l = A[0] - '0';
        int r = A[A.size() - 1] - '0';

        dp[r] = max(dp[l] + 1, dp[r]);
        m = max(m, dp[r]);
    }
    cout << n - m << endl;
    return 0;
}