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

// const ll MOD = 1e9 + 7;
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


/* ------------- Functions -------------- */

ll calc_gcd(ll a, ll b) {
    if (a > b) return calc_gcd(b, a);
    if (a == 0) return b;
    return calc_gcd(b % a, a);
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    V<string> units;
    map<string, ll> id;
    V<V<P<ll, ll>>> path(400);

    REP(i, N) {
        string s[2];
        ll m;
        cin >> s[0] >> m >> s[1];
        REP(i, 2) {
            if (!(VFIND(units, s[i]))) {
                id[s[i]] = SIZE(units);
                units.pb(s[i]);
            }
        }

        path[id[s[1]]].pb(mp(id[s[0]], m));
        path[id[s[0]]].pb(mp(id[s[1]], -m));
    }

    ll w = SIZE(units);
    V<V<P<ll, ll>>> d(w, V<P<ll, ll>>(w, {0, 1}));
    REP(i, w) {
        d[i][i] = {1, 1};
        for (auto p : path[i]) {
            if (p.snd > 0) {
                d[i][p.fst] = {p.snd, 1};
            } else {
                d[i][p.fst] = {1, -p.snd};
            }
        }
    }

    REP(k, w) {
        REP(i, w) {
            REP(j, w) {
                if (d[i][j].fst > 0 || d[i][k].fst == 0 || d[k][j].fst == 0) continue;
                d[i][j].fst = d[i][k].fst * d[k][j].fst;
                d[i][j].snd = d[i][k].snd * d[k][j].snd;
                ll gcd = calc_gcd(d[i][j].fst, d[i][j].snd);
                d[i][j].fst /= gcd;
                d[i][j].snd /= gcd;
            }
        }
    }

    ll ans = 0;
    string large, small;
    REP(i, w) {
        REP(j, w) {
            ll v = d[i][j].fst / d[i][j].snd;
            if (v > ans) {
                large = units[j];
                small = units[i];
                ans = v;
            }
        }
    }

    cout << 1 << large << "=" << ans << small << endl;
    return 0;
}
