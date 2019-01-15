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
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
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
#define SORT(v) sort((v).begin(), (v).end())
#define GSORT(v) sort((v).begin(), (v).end(), greater<decltype((v).front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (ll i = (b)-1; i >= (a); --i)

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

const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// mt19937 mt(LL(time(0)));

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
    if (n == 1) return b /* % MOD */;
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

class BIT {
public:
    // 要素数N、値vで初期化
    explicit BIT(ll N, ll v) : V_NUM(N) {
        data.resize(N);
        fill(data.begin(), data.end(), v);
    }

    // [1, i]の総和を求める
    ll query(ll i) {
        ll ret = 0;
        while (i > 0) {
            ret += data[i];
            i -= (i & -i);
        }
        return ret;
    }

    // data[i]にv可算
    void update(ll i, ll v) {
        while (i < V_NUM) {
            data[i] += v;
            i += (i & -i);
        }
    }

    ll V_NUM;
    vector<ll> data;
};

void solve() {
    ll D, F, T, N;
    cin >> D >> F >> T >> N;

    BIT bit(N + 1, 0);
    // bit[i] = iで満タンにしたときの、到達不能なパターン数

    vector<ll> X(N + 3);
    X[0] = 0;
    FOR(i, 1, N + 1) {
        cin >> X[i];
    }
    X[N + 1] = D;
    X[N + 2] = INF;

    RFOR(i, 0, N + 1) {

        ll pat = 0;
        if (X[i] + F < D) {
            ll pre = upper_bound(ALL(X), X[i] + F - T) - X.begin();
            ll lat = upper_bound(ALL(X), X[i] + F) - X.begin();
            pre = min(pre, N + 1);
            lat = min(lat, N + 1);
            pat = mypow(2LL, pre - i - 1) * mypow(2LL, N - lat + 1) % MOD;
            pat += (bit.query(lat - 1) - bit.query(pre - 1) + MOD) % MOD * mypow(2LL, pre - i - 1) % MOD;
            pat %= MOD;
            // cout << mp(pre, lat) << endl;
        }

        // cout << mp(i, pat) << endl;

        if (i > 0) {
            bit.update(i, pat);
        } else {
            cout << (mypow(2LL, N) - pat + MOD) % MOD << endl;
        }
    }

    return;
}


/* ---------- Do not edit below part ---------- */


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    FOR(_, 0, num) {
        cout << "++++++++++++++++++++" << endl;
        solve();
    }
#else
    solve();
#endif

    return 0;
}
