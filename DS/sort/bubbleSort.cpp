#include <bits/stdc++.h>

using namespace std;

#define debugVec(a) cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;

void bubbleSort(vector<int>& A) {
    int n = A.size();
    for(int i = 0; i < n - 1; i++) {
        bool f = false;
        for(int j = n - 1; j > i; j--) {
            if (A[j] > A[j-1]) {
                swap(A[j], A[j-1]);
                f = true;
            }
        }
        if (!f) return;
    }
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubbleSort(nums);
    debugVec(nums);
}