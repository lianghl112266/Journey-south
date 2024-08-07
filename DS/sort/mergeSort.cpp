#include <bits/stdc++.h>

using namespace std;
#define debug(a) cerr << #a " = " << a << endl;
#define debugVec(a) cerr << #a " = ";for (auto&& x : a) cerr << x << ' ';cerr << endl;


void merge(vector<int>& A, int l, int mid, int r) {
    vector<int> B(A.begin() + l, A.begin() + r);
    for(int i = l, j = mid, k = l; i < mid || j < r;) {
        int x = i < mid ? B[i-l] : 0x3f3f3f3f;
        int y = j < r ? B[j-l] : 0x3f3f3f3f;
        if (x < y) A[k++] = B[(i++)-l];
        else A[k++] = B[(j++)-l];
    }
} 


void mergeSort(vector<int>& A, int l, int r) {
    if (r - l > 1) {
        int mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid, r);
        merge(A, l, mid, r);
    }

}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    mergeSort(nums, 0, nums.size());
    debugVec(nums);
}