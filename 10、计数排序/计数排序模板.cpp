#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& a, int m) {
    int n = (int)a.size();
    int* count = new int[m + 1];
    memset(count, 0, sizeof(int) * (m + 1));
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    int s = 0;
    for (int v = 0; v <= m; ++v) {
        while (count[v]) {
            a[s++] = v;
            --count[v];
        }
    }
    delete[] count;
}

int main() {
    vector<int> a = { 7,6,5,4,3,1 };
    countingSort(a, 10);
    for (int i = 0; i < (int)a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
