#include <iostream>
#include <string>
using namespace std;

int slideWindow(int n, int k, const string& a) {
    int i = 0, j = -1;
    int count[256] = { 0 };
    int ret = 0;
    while (j++ < n - 1) {
        count[a[j]]++;
        while (count[a[j]] > k) {
            count[a[i]]--;
            i++;
        }
        // [i,j]
        int x = j - i + 1;
        ret = max(ret, x);
    }
    return ret;
}

int main()
{
    int n, k;
    string s;
    cin >> s;
    cin >> k;
    int ans = slideWindow(s.size(), k, s);
    cout << ans << endl;
    return 0;
}