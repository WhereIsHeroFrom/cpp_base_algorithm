#include <iostream>
#include <vector>
using namespace std;

bool isGreen(vector<int>& nums, int mid, int t) {
    return nums[mid] >= t;
}

int bSearch(vector<int>& nums, int t) {
    int l = -1;
    int r = nums.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (isGreen(nums, mid, t)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}

int main()
{
    vector<int> v = { 1,2,3,4,6,7,8,9,9,11 };
    cout << "≥ -1的最小值的下标是：" << bSearch(v, -1) << endl;
    cout << "≥ 5的最小值的下标是：" << bSearch(v, 5) << endl;
    cout << "≥ 9的最小值的下标是：" << bSearch(v, 9) << endl;
    cout << "≥ 12的最小值的下标是：" << bSearch(v, 12) << endl;
    return 0;
}