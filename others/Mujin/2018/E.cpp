/* main code starts from line 155. */

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

#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)

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

template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n;
    if (n % 2 == 0) {
        return mypow(sq(b), n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

/* --------------------
template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n % MOD;
    if (n % 2 == 0) {
        return mypow(sq(b) % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}
-------------------- */

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
const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
const ll dx[4] = {0, -1, 1, 0};
const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */


/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<char, ll> dir;
    FOR(i, 0, 3) {
        dir["LUDR"[i]] = i;
    }

    ll N, M, K;
    cin >> N >> M >> K;


    string D;
    cin >> D;

    D += D;
    V<ll> far(4, INF);
    V<V<ll>> dis(K, V<ll>(4));
    RFOR(i, K * 2 - 1, 0) {
        far[dir[D[i]]] = i;
        if (i < K) {
            FOR(j, 0, 3) {
                dis[i][j] = far[j] - i;
            }
        }
    }

    V<string> S(N);
    P<ll, ll> s, g;
    FOR(x, 0, N - 1) {
        cin >> S[x];
        FOR(y, 0, M - 1) {
            if (S[x][y] == 'S') {
                s = mp(x, y);
            } else if (S[x][y] == 'G') {
                g = mp(x, y);
            }
        }
    }

    V<V<ll>> d(N, V<ll>(M, INF));
    GPQ<P<ll, P<ll, ll>>> que;
    que.push(mp(0, s));

    while (!que.empty()) {
        ll t;
        P<ll, ll> p;
        tie(t, p) = que.top();
        que.pop();

        if (d[p.fst][p.snd] < t) continue;
        d[p.fst][p.snd] = t;

        FOR(i, 0, 3) {
            ll nx = p.fst + dx[i];
            ll ny = p.snd + dy[i];
            ll nt = t + 1 + dis[t % K][i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || S[nx][ny] == '#') continue;

            que.push(mp(nt, mp(nx, ny)));
        }
    }

    if (d[g.fst][g.snd] < INF) {
        cout << d[g.fst][g.snd] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
