#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (x < a[j]) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = x;
    }
}
int main() {
    vector<int> a = { 7,6,5,4,3,1 };
    insertionSort(a);
    for (int i = 0; i < (int)a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
