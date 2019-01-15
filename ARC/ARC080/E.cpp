/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())
#define SORT(v) sort(ALL(v))
#define GSORT(v) gsort(ALL(v))

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); --i)

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return n /* % MOD */;
    if (n % 2 == 0) {
        return mypow(sq(b) /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

// #define DEBUG
// #define DEBUG_CASE_NUM 3

const ll INF = 1LL << 50;

class Segtree {
public:
    explicit Segtree(ll N) {
        while (V_NUM < N) {
            V_NUM *= 2;
        }

        data.resize(V_NUM * 2);
        fill(ALL(data), mp(INF, -1));
    }

    // 内部処理
    // kは節点のindex、[l, r)がその対応区間
    P<ll, ll> query(ll a, ll b, ll k, ll l, ll r) {
        // [a, b)と[l, r)が交わらない場合
        if (r <= a || b <= l) return mp(INF, -1);

        // [a, b)が[l, r)を包含する場合
        if (a <= l && r <= b) return data[k];

        // 他の場合
        // [l, r)を子に分割する
        P<ll, ll> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        P<ll, ll> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    // 外部呼び出し
    // [a, b)の最小値を求める
    P<ll, ll> query(ll a, ll b) {
        return query(a, b, 0, 0, V_NUM);
    }

    // 値の更新
    void update(ll i, P<ll, ll> v) {
        i += V_NUM - 1;
        data[i] = min(data[i], v);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    ll V_NUM = 1;
    V<P<ll, ll>> data;
};


void solve() {
    ll N;
    cin >> N;

    V<Segtree> seg(2, Segtree(N));

    FOR(i, 0, N - 1) {
        ll v;
        cin >> v;
        seg[i % 2].update(i, mp(v, i));
    }

    V<ll> ans;

    GPQ<P<P<ll, ll>, P<ll, ll>>> que;
    que.push(mp(seg[0].query(0, N), mp(0, N)));

    while (!que.empty()) {
        ll val, idx, l, r;
        tie(val, idx) = que.top().fst;
        tie(l, r) = que.top().snd;
        que.pop();

        // cout << que.top() << endl;

        if (val == INF) continue;

        ans.pb(val);

        ll nval, nidx;
        tie(nval, nidx) = seg[(l + 1) % 2].query(idx + 1, r);

        ans.pb(nval);

        que.push(mp(seg[l % 2].query(l, idx), mp(l, idx)));
        que.push(mp(seg[(idx + 1) % 2].query(idx + 1, nidx), mp(idx + 1, nidx)));
        que.push(mp(seg[(nidx + 1) % 2].query(nidx + 1, r), mp(nidx + 1, r)));
    }

    for (ll v : ans) {
        cout << v << " ";
    }
    cout << endl;

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    FOR(_, 1, DEBUG_CASE_NUM) {
        solve();
        cout << "++++++++++" << endl;
    }
#else
    solve();
#endif

    return 0;
}
