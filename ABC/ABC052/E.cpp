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

const ll MOD = 1e9 + 7;
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
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(sq(b) % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

// #define DEBUG
// #define DEBUG_CASE_NUM 4

const ll MAX_V = 1000;
V<ll> fact(MAX_V + 1), invfact(MAX_V + 1);

void precalc() {
    invfact[0] = fact[0] = 1;
    FOR(i, 1, MAX_V) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX_V] = mypow(fact[MAX_V], MOD - 2);
    RFOR(i, MAX_V - 1, 0) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}

ll N, A, B, C, D;
ll dp[1010][1010];

// num人をg〜B人グループに分ける
ll dfs(ll num, ll g) {
    if (dp[num][g] >= 0) return dp[num][g];
    if (g > B) return 0;

    dp[num][g] = dfs(num, g + 1);
    FOR(i, C, D) {
        if (num >= g * i) {
            ll pat = fact[num] * mypow(invfact[g], i) % MOD * invfact[num - g * i] % MOD * invfact[i] % MOD;
            dp[num][g] += pat * dfs(num - g * i, g + 1) % MOD;
            dp[num][g] %= MOD;
        } else {
            break;
        }
    }

    // cout << mp(num, g) << " : " << dp[num][g] << endl;
    return dp[num][g];
}

void solve() {
    fill(dp[0], dp[1001], -1);
    cin >> N >> A >> B >> C >> D;

    fill(dp[0], dp[1], 1);
    cout << dfs(N, A) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);

    precalc();

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
