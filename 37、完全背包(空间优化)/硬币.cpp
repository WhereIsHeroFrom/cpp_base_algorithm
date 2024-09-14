#define maxn 5
#define maxv 1000001
#define inf 0
#define init 1
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return (a + b) % 1000000007;
}

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxv]) {
    dp[0] = init;
    for (int i = 1; i <= V; ++i) {
        dp[i] = inf;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w[i]; j <= V; ++j) {
            dp[j] = opt(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

int n, V;
int w[maxn] = { -1, 25, 10, 5, 1 };
vType v[maxn] = { -1, 0, 0, 0, 0 };
vType dp[maxv];

class Solution {
public:
    int waysToChange(int n) {
        KnapsackComplete(4, n, w, v, dp);
        return dp[n];
    }
};

// dp[i][j] 代表前 i 种硬币组合出 j 分的方案数
/*
那么第 i 种硬币可以不选，方案数就是 dp[i-1][j]
第 i 种硬币也可以选 1个，2个， k个
你会发现这个和完全背包非常相似
所以最终的状态转移方程，可以写成：
dp[i][j] = dp[i-1][j] + dp[i][j - w[i]]

它和完全背包的区别在于：
1、max 变成了 加和
2、这道题目没有价值一说，也就是每个物品价值为 0
有人就要问了，那这个 25分，10分 是什么东西？
这个是容量，或者说价格。

*/