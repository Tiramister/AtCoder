// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>

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
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define SZ(x) ((int)(x).size())
#define MEMSET(c, v) memset((c), v, sizeof(c))

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)

// constant
// const ll MOD = 1e9 + 7;
const ll INF = 1e6;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define debug(x) cout << #x << " = " << x << endl

// --------------------------------------------------------


int main()
{
    int N, MAX = -INF, MIN = INF;
    int MAXitr, MINitr;
    cin >> N;
    cout << N * 2 - 2 << endl;
    FOR(i, 1, N + 1)
    {
        int a;
        cin >> a;
        if (MAX <= a) {
            MAX = a;
            MAXitr = i;
        }
        if (MIN >= a) {
            MIN = a;
            MINitr = i;
        }
    }

    if (MIN >= 0 || (MAX > 0 && abs(MAX) >= abs(MIN))) {
        FOR(i, 1, N + 1)
        {
            if (i != MAXitr) {
                cout << MAXitr << " " << i << endl;
            }
        }
        FOR(i, 1, N)
        {
            cout << i << " " << i + 1 << endl;
        }
    } else {
        FOR(i, 1, N + 1)
        {
            if (i != MINitr) {
                cout << MINitr << " " << i << endl;
            }
        }
        RFOR(i, N, 2)
        {
            cout << i << " " << i - 1 << endl;
        }
    }
    return 0;
}
