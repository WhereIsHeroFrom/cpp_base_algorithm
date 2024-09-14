class Solution {
    int dp[200][200];

    int dir[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    int dfs(vector<vector<int>>& matrix, int m, int n, int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int len = 1;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (tx < 0 || ty < 0 || tx >= m || ty >= n) {
                continue;
            }
            if (matrix[tx][ty] <= matrix[x][y]) {
                continue;
            }
            if (dfs(matrix, m, n, tx, ty) + 1 > len) {
                len = dfs(matrix, m, n, tx, ty) + 1;
            }
        }
        dp[x][y] = len;
        return len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));

        int m = matrix.size();
        int n = matrix[0].size();
        int len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = dfs(matrix, m, n, i, j);
                len = max(len, v);
            }
        }
        return len;
    }
};