#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 10
#define ll long long
ll sum = 0;
vector<bool> visited(maxn, false);
vector<ll>ans;
void dfs(int depth, int maxdepth) {
    if (depth == maxdepth) {
        if (sum / 1000000000 == 0) {
            return;
        }
        if (sum % 11 == 0) {
            ans.push_back(sum);
            return;
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (visited[i] == true) {
            continue;
        }
        sum = sum * 10 + i;
        visited[i] = true;
        dfs(depth + 1, maxdepth);
        sum = sum / 10;
        visited[i] = false;
    }
}

int main()
{
    dfs(0, 10);
    sort(ans.begin(), ans.end());
    cout << ans.back() - ans[0] << endl;
    return 0;
}
