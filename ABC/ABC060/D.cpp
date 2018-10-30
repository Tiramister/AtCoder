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
// const ll MOD = 1e9 + 7;
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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  ll W;
  cin >> N >> W;

  VVL value(4);

  int w1, v1;
  cin >> w1 >> v1;
  value[0].push_back(v1);

  REP(i, N - 1) {
    int w, v;
    cin >> w >> v;
    value[w - w1].push_back(v);
  }

  VVL vsum(4);
  REP(i, 4) {
    GSORT(value[i]);
    vsum[i].resize(value[i].size() + 1);
    vsum[i][0] = 0;
    NREP(j, value[i].size()) {
      vsum[i][j] = vsum[i][j - 1] + value[i][j - 1];
    }
  }

  VL num(4, 0);
  ll maxV = 0;

  for (num[0] = 0; num[0] <= value[0].size(); num[0]++) {
    for (num[1] = 0; num[1] <= value[1].size(); num[1]++) {
      for (num[2] = 0; num[2] <= value[2].size(); num[2]++) {
        for (num[3] = 0; num[3] <= value[3].size(); num[3]++) {
          ll wpart = 0, vpart = 0;
          REP(i, 4) {
            wpart += num[i] * (w1 + i);
            vpart += vsum[i][num[i]];
          }
          if (wpart <= W) {
            maxV = max(maxV, vpart);
          }
        }
      }
    }
  }

  cout << maxV << endl;
  return 0;
}
