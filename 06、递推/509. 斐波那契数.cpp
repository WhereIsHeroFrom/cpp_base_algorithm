class Solution {
public
    int fib(int n) {
        int f[31];
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i = n; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};