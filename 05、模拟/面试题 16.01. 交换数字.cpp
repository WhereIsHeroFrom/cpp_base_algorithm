class Solution {
public:
    vector<int> swapNumbers(vector<int>& a) {
        a[0] = a[0] ^ a[1];
        a[1] = a[0] ^ a[1];
        a[0] = a[0] ^ a[1];
        return a;
    }
};