#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50005;
const int MAXT = 7;
const int BASE = 10;
int PowOfBase[MAXT];
int RadixBucket[BASE][MAXN];
int RadixBucketTop[BASE];

void RadixSort(vector<int>& a) {
    int n = (int)a.size();
    PowOfBase[0] = 1;
    for (int i = 1; i < MAXT; ++i) {
        PowOfBase[i] = PowOfBase[i - 1] * BASE;
    }


    for (int i = 0; i < n; ++i) {
        a[i] += PowOfBase[MAXT - 1];
    }

    int pos = 0;
    while (pos < MAXT) {
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));
        for (int i = 0; i < n; ++i) {
            int rdx = a[i] / PowOfBase[pos] % BASE;
            RadixBucket[rdx][RadixBucketTop[rdx]++] = a[i];
        }
        int top = 0;
        for (int i = 0; i < BASE; ++i) {
            for (int j = 0; j < RadixBucketTop[i]; ++j) {
                a[top++] = RadixBucket[i][j];
            }
        }
        pos++;
    }
    for (int i = 0; i < n; ++i) {
        a[i] -= PowOfBase[MAXT - 1];
    }
}
int main() {
    vector<int> a = { 7,6,5,4,3,101,178,56,332,69,40,41,28 };
    RadixSort(a);
    for (int i = 0; i < (int)a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
