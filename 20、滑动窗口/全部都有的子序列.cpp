#include <iostream>
#include <cstring>
using namespace std;

int slideWindow(int n, int* a) {
    int i = 0, j = -1;
    int count[1001] = { 0 };
    int need = 0, tot = 0;
    int ret = n;
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
        if (count[a[i]] == 1) {
            need++;
        }
    }
    memset(count, 0, sizeof(count));

    while (j < n - 1) {
        j++;
        if (++count[a[j]] == 1) {
            tot++;
        }
        while (tot == need) {
            // [i, j]
            ret = min(ret, j - i + 1);
            if (--count[a[i]] == 0) {
                tot--;
            }
            i++;
        }
    }
    return ret;
}

int a[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = slideWindow(n, a);
    printf("%d\n", ans);
    return 0;
}