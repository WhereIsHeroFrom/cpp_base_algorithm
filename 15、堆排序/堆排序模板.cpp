#include <iostream>
#include <vector>
using namespace std;

#define eleType int
#define idType int
#define maxn 50000

idType lson(idType idx) {
    return idx * 2 + 1;
}
idType rson(idType idx) {
    return idx * 2 + 2;
}
idType parent(idType idx) {
    return (idx - 1) / 2;
}
bool better(eleType a, eleType b) {
    return a > b;
}

void Heapify(vector<eleType>& heap, int size, eleType curr) {
    idType lsonId = lson(curr);
    idType rsonId = rson(curr);
    idType optId = curr;
    if (lsonId < size && better(heap[lsonId], heap[optId])) {
        optId = lsonId;
    }
    if (rsonId < size && better(heap[rsonId], heap[optId])) {
        optId = rsonId;
    }
    if (optId != curr) {
        swap(heap[curr], heap[optId]);
        Heapify(heap, size, optId);
    }
}

void HeapSort(vector<int>& nums) {
    for (int i = nums.size() / 2; i >= 0; --i) {
        Heapify(nums, nums.size(), i);
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        Heapify(nums, i, 0);
    }
}

int main() {
    vector<int> a = { 7,6,5,4,3,101,178,56,332,69,40,41,28 };
    HeapSort(a);
    for (int i = 0; i < (int)a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
