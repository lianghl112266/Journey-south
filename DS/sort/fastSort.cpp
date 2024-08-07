#include <bits/stdc++.h>

using namespace std;


#define debugVec(a) cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;



int f(vector<int>& A, int l, int r) {
    int x = A[l];
    while(l < r) {
        while(l < r && A[r] >= x) r--;
        A[l] = A[r];
        while(l < r && A[l] <= x) l++;
        A[r] = A[l];
    }
    A[l] = x;
    return l;
}


void fastSort(vector<int>& A, int l, int r) {
    if (l < r) {
        int mid = f(A, l, r);
        fastSort(A,l, mid - 1);
        fastSort(A, mid + 1, r);
    }
    
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    fastSort(nums, 0, nums.size());
    debugVec(nums);
}