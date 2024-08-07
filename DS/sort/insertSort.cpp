#include <bits/stdc++.h>

using namespace std;


#define bs
#define debugVec(a) cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;

void insertSort(vector<int>& A) {
    int n = A.size();
    for(int i = 1, j; i < n; i++) {
        if (A[i] < A[i-1]) {
            int x = A[i];
            for(j = i - 1; j >= 0 && A[j] > x; j--) {
                A[j+1] = A[j];
            }
            A[j+1] = x;
        }
    }
}


void binarySearchInsertSort(vector<int>& A) {
    int n = A.size();
    for(int i = 1; i < n; i++) {
        if (A[i] < A[i-1]) {
            int left = 0, right = i - 1, x = A[i];
            while(left <= right) {
                int mid = (left + right) / 2;
                if (A[mid] < x) left = mid + 1;
                else right = mid - 1;
            }
            for(int j = i - 1; j >= left; j--) A[j+1] = A[j];
            A[left] = x;
        }
    }
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    #ifdef bs
    binarySearchInsertSort(nums);
    #else
    insertSort(nums);
    #endif
    debugVec(nums);
}