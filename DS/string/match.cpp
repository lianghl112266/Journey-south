#include <bits/stdc++.h>

using namespace std;

#define kmp

int matchSimple(string s, string t) {
    int i = 0, j = 0, n = s.size(), m = t.size();
    while(i < n && j < m) {
        if (s[i] == t[j]) {
            i++;j++;
        }else {
            i = i - j + 1; j = 0;
        }
    }
    if (j >= m) return i - m;
    return -1;
}


int matchKMP(string s, string t, vector<int> next) {
    int i = 0, j = 0, n = s.size(), m = t.size();
    while(i <= n && j <= m) {
        if (j == -1 || s[i] == t[j]) {
            i++;j++;
        }
        else {
            j = next[j];
        }
    }
    if (j >= m) return i - m;
    return-1;
}


vector<int> getNext(string s) {
    int n = s.size();
    vector<int> next(n);
    next[0] = -1;
    for(int i = 2; i < n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            string a = s.substr(0, j);
            string b = s.substr(i-j, j);
            if (a == b) next[i] = j;
        }
    }
    return next;
}


int main() {
    string s, t;
    cin >> s;
    cin >> t;
    #ifdef kmp
    cout << matchKMP(s, t, getNext(t));
    #else
    cout << matchSimple(s, t);
    #endif
}
