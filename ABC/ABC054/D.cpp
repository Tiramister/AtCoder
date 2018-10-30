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
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// constant
// const ll MOD = 1e9 + 7;
const int INF = 1 << 25;
// const ll INF = 1LL << 50;
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

int N;
int Ma, Mb;
VVI a(3, (VI(50)));
// a[0][i]=ai, a[1][i]=bi, a[2][i]=ci
VI sum(3, 0);  // ai, biの総和を記録

int dp[41][401][401];
// dp[i][Ga][Gb] =
// 1~iまでの薬品を幾つか選んで、
// a、bの和がGa、Gbグラムとなるようなコストの最小値
// (できなければINF)

int ans = INF;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> Ma >> Mb;
  NREP(j, N) {
    REP(i, 3) {
      cin >> a[i][j];
      sum[i] += a[i][j];
    }
  }

  // i=0のときの初期条件
  REP(ga, sum[0] + 1) {
    REP(gb, sum[1] + 1) {
      dp[0][ga][gb] = INF;
    }
  }
  dp[0][0][0] = 0;

  NREP(i, N) {
    REP(ga, sum[0] + 1) {
      REP(gb, sum[1] + 1) {

        if (ga >= a[0][i] && gb >= a[1][i]) {
          dp[i][ga][gb] = min(dp[i - 1][ga][gb], dp[i - 1][ga - a[0][i]][gb - a[1][i]] + a[2][i]);
        } else {
          dp[i][ga][gb] = dp[i - 1][ga][gb];
        }
      }
    }
  }

  // a[N][ga][gb]がa、bをga、gbグラム作るときの最小コスト

  NREP(ga, sum[0]) {
    int gb = ga * Mb / Ma;
    if (ga * Mb == gb * Ma && gb <= sum[1]) {
      int cost = dp[N][ga][gb];
      if (ans > cost) {
        ans = cost;
      }
    }
  }

  cout << (ans >= INF ? -1 : ans) << endl;
  return 0;
}
