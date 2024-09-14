#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& a, int l, int r) {
    int idx = l + rand() % (r - l + 1);
    swap(a[l], a[idx]);
    int i = l, j = r;
    int x = a[i];
    while (i < j) {
        while (i < j && a[j] > x)
            j--;
        if (i < j)
            swap(a[i], a[j]), ++i;

        while (i < j && a[i] < x)
            i++;
        if (i < j)
            swap(a[i], a[j]), --j;

    }
    return i;
}

void QuickSort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivox = Partition(a, l, r);
    QuickSort(a, l, pivox - 1);
    QuickSort(a, pivox + 1, r);
}

int main() {
    vector<int> a = { 7,6,5,4,3,1 };
    QuickSort(a, 0, a.size() - 1);
    for (int i = 0; i < (int)a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
