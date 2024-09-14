#include <iostream>
#include <unordered_map>
using namespace std;

#define SB 1000000001
#define ll long long 

int n;
int A[100001];
int B[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    // A[i] == B[j]
    // B[i] == A[j]
    // A[i]*SB+B[i] == B[j]*SB+A[j]
    unordered_map <ll, int> h;
    long long ret = 0;
    for (int j = 0; j < n; ++j) {
        ll y = (ll)B[j] * SB + A[j];
        ret += h[y];
        ll x = (ll)A[j] * SB + B[j];
        h[x]++;
    }
    cout << ret << endl;

    return 0;
}