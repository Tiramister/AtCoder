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
typedef vector<VI> VII;
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
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)

// constant
// const ll MOD = 1e9 + 7;
const int INF = 1e9;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define test(x) cout << #x << " = " << x << endl

// --------------------------------------------------------


int main()
{
    int N;
    cin >> N;

    int F[N][10];
    REP(i, N)
    {
        REP(j, 10)
        {
            cin >> F[i][j];
        }
    }

    int P[N][11];
    REP(i, N)
    {
        REP(j, 11)
        {
            cin >> P[i][j];
        }
    }

    int MAXG = -INF;
    FOR(b, 1, 1 << 10)
    {
        int G = 0;

        REP(i, N)
        {
            int c = 0;
            REP(j, 10)
            {
                if ((b >> j & 1) && F[i][j]) {
                    c++;
                }
            }
            G += P[i][c];
        }

        MAXG = max(MAXG, G);
    }

    cout << MAXG << endl;
    return 0;
}
