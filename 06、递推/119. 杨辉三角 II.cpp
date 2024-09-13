class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int f[34][34];
        for(int i = 0; i <= rowIndex; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) {
                    f[i][j] = 1;
                }else
                    f[i][j] = f[i-1][j] + f[i-1][j-1];
            }
        }
        vector<int> ret;
        for(int j = 0; j <= rowIndex; ++j) {
            ret.push_back( f[rowIndex][j] );
        }
        return ret;
    }
};
