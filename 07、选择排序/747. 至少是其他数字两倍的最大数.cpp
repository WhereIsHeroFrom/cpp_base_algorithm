class Solution {
    void selectionSort(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            int min = i;
            for(int j = i + 1; j < n; ++j) {
                if(a[j] < a[min]) {
                    min = j;
                }
            }
            int tmp = a[min]; 
            a[min] = a[i];
            a[i] = tmp;
        }
    }
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[max]) {
                max = i;
            }
        }
        selectionSort(nums);
        int n = nums.size();
        if( nums[n-1] >= 2 * nums[n-2] ) {
            return max;
        }
        return -1;
    }
};