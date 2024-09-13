class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                pre = pre + 1;
                if(pre > max) {
                    max = pre;
                }
            }else {
                pre = 0;
            }
        }
        return max;
    }
};