class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 1; i < nums.size() - 1; ++i) {
            if( nums[i] != nums[i-1] && nums[i] != nums[i+1] ) {
                return nums[i];
            }
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        return nums.back();
    }
};