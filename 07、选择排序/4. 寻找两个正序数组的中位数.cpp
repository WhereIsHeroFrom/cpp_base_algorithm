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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0 ;i < nums2.size(); ++i) {
            int x = nums2[i];
            nums1.push_back(x);
        }
        selectionSort(nums1);
        int n = nums1.size();
        if(n % 2) {
            return nums1[n/2];
        }
        return (nums1[n/2-1] + nums1[n/2]) / 2.0;
    }
};