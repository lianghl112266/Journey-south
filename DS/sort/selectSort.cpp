#include <bits/stdc++.h>

using namespace std;


#define debugVec(a) cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;





void selectSort(vector<int>& A) {
    int n = A.size();
    for(int i = 0; i < n - 1; i++) {
        int idx = i;
        for(int j = i + 1; j < n; j++) {
            if (A[j] < A[idx]) idx = j;
        }
        swap(A[idx], A[i]);
    }
    
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selectSort(nums);
    debugVec(nums);
}