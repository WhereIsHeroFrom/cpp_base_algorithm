class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int f[2][34];
        int now = 1;
        int pre = 0;
        f[pre][0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    f[now][j] = 1;
                }
                else
                    f[now][j] = f[pre][j] + f[pre][j - 1];
            }
            pre = 1 - pre;
            now = 1 - now;
        }
        vector<int> ret;
        for (int j = 0; j <= rowIndex; ++j) {
            ret.push_back(f[pre][j]);
        }
        return ret;
    }
};

