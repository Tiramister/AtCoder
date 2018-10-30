/* main code starts from line 133. */

/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
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

#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<decltype((v).front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)

#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// Usual REP runs from 0 to n-1 (R: n-1 to 0)
// Natural REP runs from 1 to n (R: n to 1)

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

#define fcout cout << fixed << setprecision(10)

/* ----------- debug ---------- */

template <typename T, typename U>
void testP2(T a, U b) {
    cout << "(" << a << ", " << b << ")" << endl;
    return;
}

template <typename T>
void testV(T v) {
    cout << "[";
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
    return;
}

template <typename T>
void testV2(T v) {
    for (auto sv : v) {
        testV(sv);
    }
    cout << endl;
    return;
}

#define GET_VAR_NAME(variable) #variable
#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;
#define testP(p)                      \
    cout << GET_VAR_NAME(p) << " = "; \
    testP2(p.fst, p.snd);

/* ---------- Constants ---------- */

const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */


/* ---------- Global Variance ----------- */

ll N;
V<ll> d(110);
V<ll> val;
map<ll, ll> com;
V<V<ll>> dp(110, V<ll>(110, -1));

/* ------------- Functions -------------- */

ll mypow(ll n, ll k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;

    if (k % 2 > 0) {
        return mypow(n, k - 1) * n % MOD;
    } else {
        return mypow(n * n % MOD, k / 2);
    }
}

void compress() {
    NREP(i, N) {
        val.pb(d[i]);
    }
    val.pb(1e15);

    SORT(val);
    val.erase(unique(ALL(val)), val.end());
    testV(val);

    ll itr = 0;
    for (ll v : val) {
        com[v] = itr;
        itr++;
    }

    return;
}

// itr列目にてval[k]までfixされている場合の総パターン数
ll dfs(ll itr, ll k) {
    if (itr == N) return 1;

    testP2(itr, k);
    if (dp[itr][k] >= 0) return dp[itr][k];

    dp[itr][k] = 0;
    if (val[k] > d[itr]) {
        dp[itr][k] = dfs(itr + 1, com[d[itr]]);
    } else {
        ll ki = k;
        while (val[ki] <= d[itr]) {
            dp[itr][k] += (mypow(2, d[itr] - val[ki]) - mypow(2, d[itr] - val[ki + 1])) * dfs(itr + 1, ki) % MOD;
            dp[itr][k] %= MOD;
            ki++;
        }
    }

    return dp[itr][k];
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    V<ll> h(N + 2, 0);
    NREP(i, N) {
        cin >> h[i];
    }
    REP(i, N + 1) {
        d[i] = min(h[i], h[i + 1]);
    }
    ll over = 0;
    NREP(i, N) {
        over += h[i] - max(d[i - 1], d[i]);
    }
    test(over);

    compress();

    cout << dfs(1, 0) * mypow(2, over + 1) % MOD << endl;
    return 0;
}
