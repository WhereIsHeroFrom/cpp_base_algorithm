class Solution {
    // 0 1 2 3 4 5 6      x
    // 1 2 3 4 6 7 8      5
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
    double trimMean(vector<int>& arr) {
        insertionSort(arr);
        int n = arr.size();
        double sum = 0;
        for (int i = n / 20; i < n - n / 20; ++i) {
            sum += arr[i];
        }
        return sum * 10 / (n * 9);
    }
};