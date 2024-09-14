int dp[1000][1000];

class Solution {
    int dfs(const string& s, int l, int r) {
        if (l > r) {
            return 1;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (s[l] == s[r]) {
            dp[l][r] = dfs(s, l + 1, r - 1);
        }
        else {
            dp[l][r] = 0;
        }
        return dp[l][r];
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            ++ans;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dp[i][j] == -1) {
                    dp[i][j] = dfs(s, i, j);
                }
                if (dp[i][j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};