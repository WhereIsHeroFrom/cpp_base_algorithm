class Solution {
    void insertionSort(vector<int>& a) {
        for (int i = 1; i < a.size(); ++i) {
            int x = a[i];
            int j;
            for (j = i - 1; j >= 0; --j) {
                if (x < a[j]) {
                    a[j + 1] = a[j];
                }
                else {
                    break;
                }
            }
            a[j + 1] = x;
        }
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        insertionSort(nums);
        int minv = 10000000;
        for (int i = 0; i + k - 1 < nums.size(); ++i) {
            int l = i;
            int r = i + k - 1;
            minv = min(minv, nums[r] - nums[l]);
        }
        return minv;
    }
};