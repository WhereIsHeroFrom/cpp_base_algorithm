class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum;
        runningSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int x = runningSum[i - 1] + nums[i];
            runningSum.push_back(x);
        }
        return runningSum;
    }
};

// runningSum[i] = sum(nums[0]¡­nums[i]) = sum(nums[0]¡­nums[i-1]) + nums[i]
//               = runningSum[i-1] + nums[i]
// runningSum[i-1] = sum(nums[0]¡­nums[i-1])