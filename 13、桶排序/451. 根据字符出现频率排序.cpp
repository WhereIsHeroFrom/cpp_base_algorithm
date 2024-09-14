
class Solution {
#define ArrayType char
    vector<vector<ArrayType>> bucket;
    vector<int> count;

    void bucketSort(ArrayType* a, int n, int max) {
        bucket.clear();
        count.resize(max);
        for (int i = 0; i < max; ++i) {
            count[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++count[a[i]];
        }
        for (int i = 0; i <= n; i++) {
            bucket.push_back({});
        }
        for (int i = 0; i < max; ++i) {
            int cnt = count[i];
            bucket[cnt].push_back(i);
        }
    }

    void bucketFree() {
        bucket.clear();
    }
public:
    string frequencySort(string s) {
        bucketSort((char*)s.c_str(), s.size(), 256);
        string ans;
        for (int i = s.size(); i > 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                for (int k = 0; k < i; ++k)
                    ans += bucket[i][j];
            }
        }
        bucketFree();
        return ans;
    }
};