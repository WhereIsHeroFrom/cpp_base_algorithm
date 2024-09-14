#include <iostream>
using namespace std;


#define maxn 10

int N;
int visited[maxn];
int ans;

int pow10[maxn] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
};

// N   = 82   +  35461 / 97
//        x         z
//        10000000
int cnt(int sum) {
    int ans = 0;
    for (int i = 8; i >= 0; --i) {
        int x = sum / pow10[i];
        if (N <= x) {
            break;
        }
        int y = N - x;
        int z = sum % pow10[i];
        for (int j = 1; ; ++j) {
            int fm = z % pow10[j];
            int fz = z / pow10[j];
            if (fz < fm) {
                break;
            }
            if (fz % fm == 0) {
                if (fz / fm == y) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

void dfs(int depth, int maxDepth, int sum) {
    if (depth == maxDepth) {
        ans += cnt(sum);
        return;
    }
    for (int i = 0; i < maxDepth; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(depth + 1, maxDepth, sum * 10 + (i + 1));
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N;
    dfs(0, 9, 0);
    cout << ans << endl;
    return 0;
}