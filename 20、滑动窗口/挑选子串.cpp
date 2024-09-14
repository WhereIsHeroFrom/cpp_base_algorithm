#include <iostream>
using namespace std;

int slideWindow(int n, int k, int* a) {
    int i = 0, j = -1;
    int sum = 0;
    int ans = 0;
    while (j++ < n - 1) {
        sum += a[j];
        while (sum >= k) {
            // [i,j], [i,j+1], ..., [i,n-1]
            ans += n - j;
            sum -= a[i];
            i++;
        }
    }
    return ans;
}

int main()
{
    int n, m, k;
    int a[2001];
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = (a[i] >= m ? 1 : 0);
    }
    int ans = slideWindow(n, k, a);
    cout << ans << endl;
    return 0;
}