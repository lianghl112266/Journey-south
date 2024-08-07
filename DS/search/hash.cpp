#include <bits/stdc++.h>

using namespace std;

//本模版用inf = 0x3f3f3f3f代表位置空， -inf代表位置删除

class Hash {
private:
    int n = 10, p = 7;

    int inf = 0x3f3f3f3f;
    vector<int> a;

    //哈希函数hashfunc
    int hf(int x) {
        return x % a.size();
    }
public:

    Hash() {
        a = vector<int> (n, inf);
    }

    bool insert(int x) {
        int j = hf(x), i, n = a.size();
        if (a[j] == inf || a[j] == -inf) {
            a[j] = x;
            return true;
        }
        //处理冲突采用线性探测
        for(i = (j+1) % n;i != j && a[i] != inf && a[i] != -inf; i = (i+1)%n) {}
        if (i != j) a[i] = x;
        return i != j;
    }

    bool erase(int x) {
        int j = hf(x), i, n = a.size();
        if (a[j] == x) {
            a[j] = -inf;
            return true;
        }
        for(i = (j+1) % n;i != j && a[i] != inf && a[i] != x; i = (i+1)%n) {}
        if (i != j) {
            a[i] = -inf;
            return true;
        }
        return false;
    }

    //获取元素下标
    int get(int x) {
        int j = hf(x), i, n = a.size();
        if (a[j] == x) return j;
        for(i = (j+1) % n;i != j && a[i] != inf && a[i] != x; i = (i+1)%n) {}
        return i != j && a[i] != inf ? i : -1;
    }

    //计算装填因子和存储效率
    vector<float> loadFactorAStorageEfficiency() {
        //计算装入元素个数
        int cnt = 0;
        for(auto x: a) if (x != inf && x != -inf) cnt++;
        return {(float)cnt/a.size(), (float)cnt/a.size() * 100};
    }


    //计算成功时ASL
    float successASL() {
        //cnt比较次数，e为元素数量
        int cnt = 0, e = 0;
        for(int i = 0; i < n; i++) {
            if (a[i] != inf && a[i] != -inf) {
                e++;
                int idx = hf(a[i]);
                cnt += (idx-i+1+n) % n;
            }
        }
        return (float)cnt/e;
    }


    float failureASL() {
        int cnt = 0;
        for(int i = 0; i < p; i++) {
            cnt++;
            if (a[i] == inf) continue;
            for(int j = i + 1; j != i && a[j] != inf; j = (j+1)%n) {
                cnt++;
            }
            cnt++;
        }
        return (float)cnt/p;
    }


};



int main() {
    Hash h = Hash();
    h.insert(10);
    h.insert(30);
    h.insert(50);
    h.erase(30);
    cout << h.get(50);
    return 0;
}