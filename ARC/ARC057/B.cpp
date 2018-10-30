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
const ll INF = 1LL << 50;
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

ll N, K;
VL a(2020);
VL S(2020);
// aの部分和

VVL dp(2020, VL(2020, INF));
// dp[d][h] = d日間でh日機嫌が良くなるような
//            総勝利数の最小値

/* ---------- Functions ---------- */

void calc_dp() {

  dp[0][0] = 0;
  // dp[0][j] = INF (j > 0)

  dp[1][0] = 0;
  dp[1][1] = 1;
  // この辺はヌルポやゼロ割りの関係で例外処理

  FOR(d, 2, N + 1) {
    dp[d][0] = 0;

    NREP(h, d) {
      ll must_win = S[d] * dp[d - 1][h - 1] / S[d - 1] + 1;
      if (must_win > S[d] || must_win - dp[d - 1][h - 1] > a[d]) {
        must_win = INF;
      }
      dp[d][h] = min(dp[d - 1][h], must_win);
    }
  }
  return;
}

/* ---------- Main Function ---------- */

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  NREP(i, N) {
    cin >> a[i];
    S[i] = S[i - 1] + a[i];
  }

  calc_dp();
  RREP(h, N) {
    if (dp[N][h] <= K) {
      cout << h << endl;
      break;
    }
  }
  return 0;
}
