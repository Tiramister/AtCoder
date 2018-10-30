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

const ll MOD = 1e9 + 7;
const int INF = 1 << 25;
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

int N, M, a, b;

VVB path(110, VB(110, false));
// 隣接行列

VI dist(110, INF);
// aからの最短距離

VL ways(110);
// 最短経路の数%MOD

queue<int> townque;
// 訪れる予定の街

/* ---------- Functions ---------- */

void bfs() {
  while (!townque.empty()) {

    int from = townque.front();
    NREP(to, N) {
      if (path[from][to]) {
        if (dist[to] > dist[from] + 1) {
          // 最短路更新(もとい街発見)
          dist[to] = dist[from] + 1;
          ways[to] = ways[from];
          townque.push(to);
        } else if (dist[to] == dist[from] + 1) {
          // 別の最短路発見
          ways[to] += ways[from];
          ways[to] %= MOD;
        }
      }
    }
    townque.pop();
  }
  return;
}

/* ---------- Main Function ---------- */

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> a >> b >> M;
  REP(i, M) {
    int x, y;
    cin >> x >> y;
    path[x][y] = true;
    path[y][x] = true;
  }

  dist[a] = 0;
  ways[a] = 1;
  townque.push(a);
  bfs();

  cout << ways[b] << endl;
  return 0;
}
