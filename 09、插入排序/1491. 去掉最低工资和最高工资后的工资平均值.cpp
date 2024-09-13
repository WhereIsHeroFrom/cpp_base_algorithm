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
    double average(vector<int>& salary) {
        insertionSort(salary);
        double sum = 0;
        int n = salary.size();
        for (int i = 1; i < n - 1; ++i) {
            sum += salary[i];
        }
        return sum / (n - 2);
    }
};