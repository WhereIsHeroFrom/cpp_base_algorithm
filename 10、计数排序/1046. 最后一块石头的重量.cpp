class Solution {
    void countingSort(vector<int>& a, int m) {
        int n = a.size();
        int* count = new int[m + 1];
        memset(count, 0, sizeof(int) * (m + 1));
        for (int i = 0; i < n; ++i) {
            count[a[i]]++;
        }
        int s = 0;
        for (int v = 0; v <= m; ++v) {
            while (count[v]) {
                a[s++] = v;
                --count[v];
            }
        }
        delete[] count;
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            countingSort(stones, 1000);
            int n = stones.size();
            int v = stones[n - 1] - stones[n - 2];
            stones.pop_back();
            stones.pop_back();
            if (v || stones.size() == 0) {
                stones.push_back(v);
            }
        }
        return stones[0];
    }
};