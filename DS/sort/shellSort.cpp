#include <bits/stdc++.h>

using namespace std;


#define debugVec(a) cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;

void shellSort(vector<int>& A) {
    int n = A.size();
    for(int d = n / 2, j; d >= 1; d /= 2) {
        for(int i = d; i < n; i++) {
            if (A[i] < A[i - d]) {
                int x = A[i];
                for(j = i - d; j >= 0 && A[j] > x; j -= d) A[j+d] = A[j];
                A[j + d] = x;
            }
        }
        for(auto x: A) cout << x << " ";
        cout << endl;
    }
}


int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    shellSort(nums);
    debugVec(nums);
}