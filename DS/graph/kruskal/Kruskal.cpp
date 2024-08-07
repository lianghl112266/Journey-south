#include <bits/stdc++.h>
using namespace std;

/* macro helpers */
#define __DECOMPOSE_S(a, x) auto x = a;
#define __DECOMPOSE_N(a, ...) auto [__VA_ARGS__] = a;
constexpr void __() {}
#define __AS_PROCEDURE(...) __(); __VA_ARGS__; __()

/* type aliases */
#if LONG_LONG_MAX != INT64_MAX
using ll = int64_t;
using ull = uint64_t;
#else
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#endif
using int128 = __int128_t;
using uint128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using pid = pair<int, ld>;
using pdi = pair<ld, int>;
using pld = pair<ll, ld>;
using pdl = pair<ld, ll>;
using pdd = pair<ld, ld>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;

/* method aliases */
#define pb push_back
#define eb emplace_back

/* constants */
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll MOD = 1e9 + 7;
constexpr int128 INT128_MAX = numeric_limits<int128>::max();
constexpr uint128 UINT128_MAX = numeric_limits<uint128>::max();
constexpr int128 INT128_MIN = numeric_limits<int128>::min();
constexpr uint128 UINT128_MIN = numeric_limits<uint128>::min();

/* random */
mt19937 rd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

/* bit-wise operations */
#define lowbit(x) ((x) & -(x))
#define popcount(x) (__builtin_popcountll(ll(x)))
#define parity(x) (__builtin_parityll(ll(x)))
#define msp(x) (63LL - __builtin_clzll(ll(x)))
#define lsp(x) (__builtin_ctzll(ll(x)))

/* arithmetic operations */
#define mod(x, y) ((((x) % (y)) + (y)) % (y))

/* conditions */
#define loop while (1)

/* build data structures */
#define edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v), ch[v].push_back(u);)
#define edgew(ch, u, v, w) __AS_PROCEDURE(ch[u].emplace_back(v, w), ch[v].emplace_back(u, w);)
#define Edge(ch, u, v) __AS_PROCEDURE(ch[u].push_back(v);)
#define Edgew(ch, u, v, w) __AS_PROCEDURE(ch[u].emplace_back(v, w);)

/* io */
#define untie __AS_PROCEDURE(ios_base::sync_with_stdio(0), cin.tie(NULL))
template<typename T> void __read(T& x) { cin >> x; }
template<typename T, typename... U> void __read(T& x, U&... args) { cin >> x; __read(args...); }
#define read(type, ...) __AS_PROCEDURE(type __VA_ARGS__; __read(__VA_ARGS__);)
#define readvec(type, a, n) __AS_PROCEDURE(vector<type> a(n); for (auto& x : a) cin >> x;)
#define debug(x) __AS_PROCEDURE(cerr << #x" = " << (x) << endl;)
#define debugvec(a) __AS_PROCEDURE(cerr << #a" = "; for (auto&& x : a) cerr << x << ' '; cerr << endl;)
template<typename T, typename U> istream& operator>>(istream& in, pair<T, U>& p) {
    return in >> p.first >> p.second;
}
template<typename T, typename U> ostream& operator<<(ostream& out, const pair<T, U>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (auto&& i : vec) out << i << ' ';
    return out;
}

/* pops */
#define poptop(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.top(); q.pop();)
#define popback(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.back(); q.pop_back();)
#define popfront(q, ...) __AS_PROCEDURE(auto [__VA_ARGS__] = q.front();q.pop_front();)

/* math */
template <typename return_t>
return_t qpow(ll b, ll p) {
    if (b == 0 and p != 0) return 0;
    if (p == 0) return 1;
    return_t half = qpow<return_t>(b, p / 2);
    if (p % 2 == 1) return half * half * b;
    else return half * half;
}
#define comb(n, k) ((n) < 0 or (k) < 0 or (n) < (k) ? 0 : fact[n] / fact[k] / fact[(n) - (k)])
constexpr inline int lg2(ll x) { return x == 0 ? -1 : sizeof(ll) * 8 - 1 - __builtin_clzll(x); }
vector<pii> decompose_prime(int N) {
    // return (factor, count)
    vector<pii> result;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            int cnt = 0;
            while (N % i == 0) N /= i, ++cnt;
            result.emplace_back(i, cnt);
        }
    }
    if (N != 1) {
        result.emplace_back(N, 1);
    }
    return result;
}

/////////////////////////////////////////////////////////

#define SINGLE_TEST_CASE
//#define DUMP_TEST_CASE 1
//define TOT_TEST_CASE 6
void dump() {}
void dump_ignore() {}

void prep() {
}


void solve() {
    read(int, n, m);

    vector<vector<int>> ee;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        ee.pb({u, v, w});
    }
    sort(ee.begin(), ee.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int pa[n];
    for(int i = 0; i < n; i++) pa[i] = i;

    function<int(int)> find = [&](int x) -> int {
        if (x != pa[x]) pa[x] = find(pa[x]);
        return pa[x];
    };

    auto merge = [&](int x, int y) -> bool {
        int rootX = find(x), rootY = find(y);
        pa[rootX] = rootY;
        return rootX != rootY;
    };
    int cur = 0;
    vector<pii> select;
    for(auto e: ee) {
        int x = e[0], y = e[1], w = e[2];
        if (merge(x, y)) {
            select.eb(x, y);
            if (cur++ == n - 1) break;
        }
    }

    debugvec(select);
}

int main() {
    untie;
    prep();
#ifdef SINGLE_TEST_CASE
    solve();
#else
    read(int, t);
    for (int i = 0; i < t; ++i) {
#ifdef DUMP_TEST_CASE
        if (t != (TOT_TEST_CASE)) {
            solve();
        } else if (i + 1 == (DUMP_TEST_CASE)) {
            dump();
        } else {
            dump_ignore();
        }
#else
        solve();
#endif
    }
#endif
}