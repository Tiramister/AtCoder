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
const ll INF = 1LL << 50;
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
V<V<P<ll, ll>>> path(100010);

/* ------------- Functions -------------- */

V<ll> bfs(ll S, ll T) {
    GPQ<P<ll, ll>> que;
    que.push(mp(0, S));

    V<ll> d(N, INF);

    while (!que.empty()) {
        ll c, v;
        tie(c, v) = que.top();
        que.pop();
        if (d[v] <= c) continue;

        d[v] = c;
        if (v == T) break;

        for (auto p : path[v]) {
            ll sv = p.fst, sc = p.snd;
            que.push(mp(d[v] + sc, sv));
        }
    }

    return d;
}

V<ll> calcpat(const V<ll>& d, ll s) {
    V<P<ll, ll>> dis;
    REP(v, N) {
        if (d[v] == INF) continue;
        dis.pb(mp(d[v] * s, v));
    }

    SORT(dis);

    V<ll> pat(N, 0);
    pat[(dis.front()).snd] = 1;

    for (auto p : dis) {
        ll v = p.snd;
        for (auto q : path[v]) {
            ll sv, c;
            tie(sv, c) = q;
            if (d[sv] - d[v] == c * s) {
                pat[sv] += pat[v];
                pat[sv] %= MOD;
            }
        }
    }

    return pat;
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;

    REP(_, M) {
        ll u, v, c;
        cin >> u >> v >> c;
        path[u - 1].pb(mp(v - 1, c));
        path[v - 1].pb(mp(u - 1, c));
    }

    V<ll> d = bfs(S, T);

    V<V<ll>> pat(2);
    pat[0] = calcpat(d, 1);
    pat[1] = calcpat(d, -1);

    ll md = d[T];

    ll ans = sq(pat[0][T]) % MOD;
    REP(v, N) {
        if (d[v] * 2 == md) {
            ans += MOD - sq(pat[0][v] * pat[1][v] % MOD) % MOD;
            ans %= MOD;
        }
    }

    REP(v, N) {
        for (auto p : path[v]) {
            ll sv, c;
            tie(sv, c) = p;
            if (d[sv] - d[v] != c) continue;
            if (d[v] * 2 < md && d[sv] * 2 > md) {
                ans += MOD - sq(pat[0][v] * pat[1][sv] % MOD) % MOD;
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}