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
const ll MOD = 1e9 + 7;
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

int N;
VS S(2);
VB vert;
bool pre;

ll calc(int i) {
  if (i >= vert.size()) {
    return 1;
  }

  if (i == 0) {
    if (vert[i]) {
      return 3 * calc(i + 1) % MOD;
    } else {
      return 6 * calc(i + 1) % MOD;
    }
  } else {
    if (vert[i - 1]) {
      return 2 * calc(i + 1) % MOD;
    } else if (vert[i]) {
      return calc(i + 1);
    } else {
      return 3 * calc(i + 1) % MOD;
    }
  }
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> S[0] >> S[1];

  REP(i, N) {
    if (S[0][i] == S[1][i]) {
      vert.push_back(true);
    } else {
      vert.push_back(false);
      i++;
    }
  }

  cout << calc(0) << endl;

  return 0;
}
