#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 10

int visited[maxn];
int stack[maxn];
int cnt;
int ans;

string str;
string sorted;

void dfs(int depth, int maxDepth) {
    if (depth == maxDepth) {
        // stack 存储了 [0, maxDepth-1] 的全排列
        int i;
        for (i = 0; i < maxDepth; ++i) {
            int idx = stack[i];
            if (sorted[idx] != str[i]) {
                break;
            }
        }
        if (i == maxDepth) {
            ans = cnt;
        }
        ++cnt;
        return;
    }
    for (int i = 0; i < maxDepth; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            stack[depth] = i;
            dfs(depth + 1, maxDepth);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> str;

    sorted = str;
    sort(sorted.begin(), sorted.end());

    memset(visited, 0, sizeof(visited));
    cnt = 0;
    dfs(0, str.size());

    cout << ans << endl;

    return 0;
}