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
// const int INF = 1 << 25;
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

VVB path(10, VB(10, false));
// 与えられたグラフの隣接行列
// path[a][b] = true <=> a-b間に辺がある

int N, M;
int ans = 0;
int vcount = 0;         // いくつの頂点を訪れたかを記録する
VB visited(10, false);  // 各頂点に訪れたか否かを記録する


void dfs(int from) {

  visited[from] = true;
  vcount++;

  if (vcount == N) {
    ans++;
  } else {

    NREP(to, N) {
      if (!visited[to] && path[from][to]) {
        dfs(to);
      }
    }
  }

  visited[from] = false;
  vcount--;
  return;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  REP(i, M) {
    int a, b;
    cin >> a >> b;
    path[a][b] = path[b][a] = true;
  }

  dfs(1);

  cout << ans << endl;

  return 0;
}
