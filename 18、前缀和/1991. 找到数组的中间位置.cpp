class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum[210];
        int n = nums.size();
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            int middleIndex = i;
            int a = 0, b = 0;
            if (middleIndex)
                a = sum[middleIndex - 1];
            b = sum[n - 1] - sum[middleIndex];
            if (a == b) {
                return middleIndex;
            }
        }
        return -1;
    }
};