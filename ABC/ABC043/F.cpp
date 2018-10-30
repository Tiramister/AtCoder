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

// namespace
using namespace std;

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;

// conversion
#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)

// container
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define GSORT(c) sort((c).begin(), (c).end(), greater<decltype((c).front())>())
#define SZ(x) (INT((x).size()))
#define MEMSET(c, v) memset((c), v, sizeof(c))

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// constant
const ll MOD = 1e9 + 7;
// const int INF = 1<<25;
// const ll INF = 1LL<<50;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define test(x) cout << #x << " = " << x << endl

// answer output
#define Yes(c) cout << ((c) ? "Yes" : "No") << endl;
#define YES(c) cout << ((c) ? "YES" : "NO") << endl;
#define yes(c) cout << ((c) ? "yes" : "no") << endl;

#define possible(c) cout << ((c) ? "possible" : "impossible") << endl;
#define POSSIBLE(c) cout << ((c) ? "POSSIBLE" : "INPOSSIBLE") << endl;


// --------------------------------------------------------


vector<VVL> dp(310, VVL(310, VL(310, 0)));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  string s;
  cin >> N >> s;
  ll S = SZ(s);

  if (N > 300) {
    cout << "f**k" << endl;
    return 0;
  }

  dp[0][0][0] = 1;

  NREP(i, N) {
    REP(j, N + 1) {
      REP(k, N + 1) {
        cout << i << " : " << j << " : " << k << endl;

        if (j > k) {

          if (j > 0) {
            dp[i][j][k] += dp[i - 1][j - 1][k];  // 0
          }
          if (j > S) {
            dp[i][j][k] += dp[i - 1][j - 1][k];  // 文字数超過
          }
          dp[i][j][k] += dp[i - 1][j + 1][k];  // B

        } else if (j == k) {

          if (k <= S && j > 0) {
            dp[i][j][k] += dp[i - 1][j - 1][k - 1];  // 1
          }
          dp[i][j][k] += dp[i - 1][j + 1][k];
          dp[i][j][k] += dp[i - 1][j + 1][k + 1];  // B
        }

        if (j == 0) {
          dp[i][j][k] += dp[i - 1][0][k];  // B空打ち
        }

        dp[i][j][k] %= MOD;
        test(dp[i][j][k]);
      }
    }
  }

  cout << dp[N][S][S] << endl;
  return 0;
}
