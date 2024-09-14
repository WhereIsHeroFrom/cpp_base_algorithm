#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200001
int A[maxn], B[maxn], C[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        C[i] = 2 * A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    sort(C, C + n);
    sort(B, B + n);
    int i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        if (C[i] > B[j]) {
            j += 1;
            ans += 1;
        }
        i += 1;
    }
    cout << ans << endl;

    return 0;
}