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
#include <set>
#include <string>
#include <vector>

// namespace
using namespace std;

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;

// container
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define GSORT(c) sort((c).begin(), (c).end(), greater<decltype((c).front())>())
#define SZ(x) ((int)(x).size())
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
// const int INF = 1e9;
// const ll INF = 1e15;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define test(x) cout << #x << " = " << x << endl

// answer output
#define Yes(c) cout << ((c) ? "Yes" : "No") << endl;
#define YES(c) cout << ((c) ? "YES" : "NO") << endl;
#define possible(c) cout << ((c) ? "possible" : "impossible") << endl;
#define POSSIBLE(c) cout << ((c) ? "POSSIBLE" : "INPOSSIBLE") << endl;


// --------------------------------------------------------


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N == 3) {
    cout << 2 << " " << 3 << " " << 25 << endl;
    return 0;
  }

  int j = 1, mod2 = 0, mod3 = 0, mod5 = 0;
  REP(i, N - 2) {
    while (true) {
      j++;
      if (j % 2 == 0 || j % 3 == 0 || j % 5 == 0) {
        cout << j << " ";
        mod2 = (mod2 + j) % 2;
        mod3 = (mod3 + j) % 3;
        mod5 = (mod5 + j) % 5;
        break;
      }
    }
  }

  while (true) {
    j++;
    if ((j + mod2) % 2 == 0 && (j + mod5) % 5 == 0 && j % 3 == 0) {
      cout << j << " ";
      break;
    }
  }

  while (true) {
    j++;
    if ((j + mod3) % 3 == 0 && j % 10 == 0) {
      cout << j << endl;
      return 0;
    }
  }
}
