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


int main()
{
    int N;
    cin >> N;
    VVI A(3, VI(N));
    REP(i, 3)
    {
        REP(j, N)
        {
            cin >> A[i][j];
        }
        GSORT(A[i]);
    }

    vector<ll> mnum(N, 0);
    int bitr = 0;
    REP(mitr, N)
    {
        if (mitr > 0) {
            mnum[mitr] = mnum[mitr - 1];
        }
        while (A[2][bitr] > A[1][mitr] && bitr < N) {
            mnum[mitr]++;
            bitr++;
        }
    }

    vector<ll> tnum(N, 0);
    int mitr = 0;
    REP(titr, N)
    {
        if (titr > 0) {
            tnum[titr] = tnum[titr - 1];
        }
        while (A[1][mitr] > A[0][titr] && mitr < N) {
            tnum[titr] += mnum[mitr];
            mitr++;
        }
    }

    cout << accumulate(tnum.begin(), tnum.end(), 0LL) << endl;
    return 0;
}
