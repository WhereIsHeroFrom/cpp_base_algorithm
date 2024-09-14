class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int middleIndex = i;
            int a = 0, b = 0;
            if (middleIndex)
                a = nums[middleIndex - 1];
            b = nums[n - 1] - nums[middleIndex];
            if (a == b) {
                return middleIndex;
            }
        }
        return -1;
    }
};