/* main code starts from line 123. */

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
#include <deque>
#include <list>
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

using ll = long long;
using PL = P<ll, ll>;
using PS = P<string, ll>;

using VI = V<int>;
using VVI = V<VI>;
using VL = V<ll>;
using VVL = V<VL>;
using VS = V<string>;
using VB = V<bool>;
using VVB = V<VB>;
using VPL = V<PL>;
using VPS = V<PS>;

#define fst first
#define snd second
#define pb push_back


/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)


/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define EACH(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)
#define REACH(i, v) for (auto itr = (v).rbegin(); itr != (v).rend(); itr++)

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


/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = 3.14159265358979;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};


/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}


/* ---------- Debug ---------- */

#define GET_VAR_NAME(variable) #variable

#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;
#define testP(p) cout << GET_VAR_NAME(p) << " = (" << (p).fst << ", " << (p).snd << ")" << endl;
#define testP2(a, b) cout << "(" << a << ", " << b << ")" << endl;


/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    VI tsum(N + 1);
    tsum[0] = 0;
    NREP(i, N) {
        int t;
        cin >> t;
        tsum[i] = tsum[i - 1] + t;
    }

    VI v(N + 2);
    v[0] = v[N + 1] = 0;
    NREP(i, N) {
        cin >> v[i];
    }

    V<double> mv(tsum[N] * 2 + 1, 1e8);

    // 加速条件
    REP(i, N + 1) {
        double pv = v[i];
        FOR(t, tsum[i] * 2, tsum[N] * 2 + 1) {
            mv[t] = min(pv, mv[t]);
            pv += 0.5;
        }
    }

    // 減速条件
    NREP(i, N + 1) {
        double pv = v[i];
        RREP(t, tsum[i - 1] * 2 + 1) {
            mv[t] = min(pv, mv[t]);
            pv += 0.5;
        }
    }

    // 等速条件
    NREP(i, N + 1) {
        double pv = v[i];
        FOR(t, tsum[i - 1] * 2, tsum[i] * 2) {
            mv[t] = min(pv, mv[t]);
        }
    }

    double ans = 0;
    REP(i, tsum[N] * 2 + 1) {
        ans += (mv[i] + mv[i + 1]) * 0.5 / 2;
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}
