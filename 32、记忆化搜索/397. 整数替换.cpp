class Solution {
    unordered_map<int, int> hash;
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (hash.find(n) != hash.end()) {
            return hash[n];
        }
        int ans;
        if (n % 2 == 0) {
            ans = integerReplacement(n / 2) + 1;
        }
        else {
            ans = min(integerReplacement(n / 2 + 1) + 1, integerReplacement(n - 1)) + 1;
        }
        hash[n] = ans;
        return ans;
    }
};