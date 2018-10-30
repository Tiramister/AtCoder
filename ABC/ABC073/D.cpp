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

// container
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define GSORT(c) sort((c).begin(), (c).end(), greater<typeof((c).front())>())
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
const int INF = 1e9;
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

int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    VI r(R);
    REP(i, R) {
        cin >> r[i];
    }

    VVI d(N + 1, VI(N + 1, INF));

    NREP(i, N) {
        d[i][i] = 0;
    }

    REP(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        d[A][B] = d[B][A] = C;
    }

    NREP(k, N) {
        NREP(i, N) {
            NREP(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int min_cost = INF;

    REP(k, fact(R)) {
        int cost = 0;
        REP(i, R - 1) {
            cost += d[r[i]][r[i + 1]];
        }
        min_cost = min(min_cost, cost);
        next_permutation(r.begin(), r.end());
    }

    cout << min_cost << endl;

    return 0;
}
