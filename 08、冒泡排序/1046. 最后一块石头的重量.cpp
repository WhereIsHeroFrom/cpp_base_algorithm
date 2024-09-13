class Solution {
    void bubbleSort(vector<int>& a) {
        int n = a.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        }
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            bubbleSort(stones);
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