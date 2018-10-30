/* main code starts from line 130. */

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
#define VFIND(v, k) find(ALL(v), k) != (v).end

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

const ll MOD = 1777777777;
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

const ll MAX_V = 800000;
V<ll> fact(MAX_V + 1), invfact(MAX_V + 1);

/* ------------- Functions -------------- */

ll pat(ll k) {
    if (k == 0) return 1;
    ll ret = pat(k - 1) * k % MOD;
    return (k % 2 == 0) ? ret + 1 : ret - 1;
}

ll calc_pow(ll n, ll k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    if (k % 2 > 0) {
        return calc_pow(n, k - 1) * n % MOD;
    } else {
        return calc_pow(n * n % MOD, k / 2);
    }
}

void precalc() {
    invfact[0] = fact[0] = 1;
    NREP(i, MAX_V) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX_V] = calc_pow(fact[MAX_V], MOD - 2);
    RREP(i, MAX_V) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}

ll comb(ll a, ll b) {
    if (a < b) return 0;
    if (a == 0) return 1;  // a = b = 0

    ll mot = 1;
    REP(i, b) {
        mot = (mot * ((a - i) % MOD)) % MOD;
    }

    return mot * invfact[b] % MOD;
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    precalc();

    ll N, K;
    cin >> N >> K;
    cout << comb(N, K) * pat(K) % MOD << endl;
    return 0;
}
