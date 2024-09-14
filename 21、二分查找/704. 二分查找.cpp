class Solution {
    bool isGreen(vector<int>& nums, int mid, int t) {
        return nums[mid] >= t;
    }

    int bSearch(vector<int>& nums, int t) {
        int l = -1;
        int r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (isGreen(nums, mid, t)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
public:
    int search(vector<int>& nums, int target) {
        int idx = bSearch(nums, target);
        if (idx == nums.size()) {
            return -1;
        }
        if (nums[idx] != target) {
            return -1;
        }
        return idx;
    }
};