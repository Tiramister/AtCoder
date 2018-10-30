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


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    V<char> c(N * 2);
    V<ll> a(N * 2);

    REP(k, N * 2) {
        cin >> c[k] >> a[k];
    }

    V<V<ll>> black(N + 1, V<ll>(N + 1, 0));
    V<V<ll>> white(N + 1, V<ll>(N + 1, 0));
    // black[i][j]
    // = 黒iより前にある(黒i+1以上の個数)
    //                + (白j+1以上の個数)

    V<bool> bused(N + 1, false);
    V<bool> wused(N + 1, false);
    // bused[i] = 黒iがすでに現れたか

    REP(k, N * 2) {
        V<ll> bsum(N + 1, 0);
        V<ll> wsum(N + 1, 0);
        // bsum[i] = i+1以上の黒がいくつ現れたか
        // bsum[0]には今までの黒の数が入る

        RREP(i, N) {
            bsum[i] = bused[i + 1] + bsum[i + 1];
            wsum[i] = wused[i + 1] + wsum[i + 1];
        }

        if (c[k] == 'B') {
            REP(j, N + 1) {
                black[a[k]][j] = bsum[a[k]] + wsum[j];
            }
            bused[a[k]] = true;
        } else {
            REP(i, N + 1) {
                white[i][a[k]] = bsum[i] + wsum[a[k]];
            }
            wused[a[k]] = true;
        }
    }

    V<V<ll>> dp(N + 1, V<ll>(N + 1, 0));
    // dp[i][j] =
    // 黒をi個、白をj個置いたときの最小手数

    REP(i, N + 1) {
        REP(j, N + 1) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + white[i][j];
                continue;
            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + black[i][j];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j] + black[i][j], dp[i][j - 1] + white[i][j]);
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}
