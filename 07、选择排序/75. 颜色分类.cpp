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
    void sortColors(vector<int>& nums) {
        selectionSort(nums);
    }
};