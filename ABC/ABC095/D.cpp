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


/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)


/* ---------- container ---------- */

#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define GSORT(c) sort(ALL(c), greater<decltype((c).front())>())
#define SZ(x) (LL((x).size()))


/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// Usual REP runs from 0 to n-1 (R: n to 0)
// Natural REP runs from 1 to n (R: n to 1)


/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};


/* ---------- Debug ---------- */
#define GET_VAR_NAME(variable) #variable

#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;

template <typename T>

void testVector(T& v) {
    REP(i, SZ(v)) {
        cout << i << ":" << v << endl;
    }
}


/* ^^^^^^^^^^^^^^^ Settting Part ^^^^^^^^^^^^^^^ */

/* ---------- Variances ---------- */

/* ---------- Functions ---------- */


/* ---------- Main Function ---------- */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, C;
    cin >> N >> C;

    vector<ll> x(N + 2), v(N + 2);
    for (ll i = 1; i <= N; i++) {
        cin >> x[i] >> v[i];
    }
    x[0] = 0;
    x[N + 1] = C;

    ll cal = 0;
    vector<vector<ll>> dp(2, vector<ll>(100010, 0));

    for (ll i = 1; i <= N; i++) {
        cal -= x[i] - x[i - 1];
        cal += v[i];
        dp[0][i] = max(dp[0][i - 1], cal);
        // ここでそれまでのカロリーの最大値をメモ
    }

    cal = 0;
    for (ll i = N; i >= 1; i--) {
        cal -= x[i + 1] - x[i];
        cal += v[i];
        dp[1][i] = max(dp[1][i + 1], cal);
    }

    ll maxcal = 0;
    for (ll i = 0; i <= N; i++) {
        // 時計回り
        cal = dp[0][i] + dp[1][i + 1] - x[i];
        maxcal = max(maxcal, cal);

        // 反時計回り
        cal = dp[0][i] + dp[1][i + 1] - C + x[i + 1];
        maxcal = max(maxcal, cal);
    }

    cout << maxcal << endl;

    return 0;
}
