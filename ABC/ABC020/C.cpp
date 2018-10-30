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
const ll dx[4] = {0, -1, 1, 0};
const ll dy[4] = {-1, 0, 0, 1};
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

int H, W, T;
VS field(20);
// field[0][0] ~ field[H-1][W-1]
PL start, goal;

/* ---------- Functions ---------- */

bool inArea(PL s) {
  return s.fst >= 0 && s.fst < H && s.snd >= 0 && s.snd < W;
}

bool bfs(ll x) {
  queue<PL> visit;
  visit.push(start);

  VVL d(H, VL(W, INF));
  d[start.fst][start.snd] = 0;

  while (!visit.empty()) {
    PL from = visit.front();

    REP(i, 4) {
      PL to = {from.fst + dx[i], from.snd + dy[i]};
      if (inArea(to)) {
        ll cost = ((field[to.fst][to.snd] == '#') ? x : 1);
        if (d[to.fst][to.snd] > d[from.fst][from.snd] + cost) {
          d[to.fst][to.snd] = d[from.fst][from.snd] + cost;
          visit.push(to);
        }
      }
    }

    visit.pop();
  }

  return d[goal.fst][goal.snd] <= T;
}

/* ---------- Main Function ---------- */

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> T;
  REP(i, H) {
    cin >> field[i];
    REP(j, W) {
      if (field[i][j] == 'S') {
        start = {i, j};
      } else if (field[i][j] == 'G') {
        goal = {i, j};
      }
    }
  }

  ll ok = 1, ng = T;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (bfs(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;
  return 0;
}
