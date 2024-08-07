#include <bits/stdc++.h>

using namespace std;

#define debugVec(a) cerr << #a " = ";for (auto&& x : a) cerr << x << ' ';cerr << endl;


void fix(vector<int>& nums, int k, int n) {
    int i = (k + 1) * 2 - 1;
    if (i >= n) return;
    if (i + 1 < n && nums[i + 1] > nums[i]) i++;
    if (nums[k] < nums[i]) {
        swap(nums[k], nums[i]);
        fix(nums, i, n);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) fix(nums, i, n);
    for (int i = n - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        fix(nums, 0, i);
    }
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    heapSort(nums);
    debugVec(nums);
}