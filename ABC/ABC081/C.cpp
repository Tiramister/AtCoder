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
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FIND(i, c) ((c).find(i) != (c).end())
#define SORT(c) sort((c).begin(), (c).end())
#define SZ(x) ((int)(x).size())
#define MEMSET(c, v) memset((c), v, sizeof(c))

//repetition
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)

// constant
// const ll MOD = 1e9 + 7;
// const ll INF = 1e12;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define debug(x) cout << #x << " = " << x << endl

// --------------------------------------------------------


int main()
{
    int N, K;
    cin >> N >> K;
    VI num(N + 1, 0);

    REP(i, N)
    {
        int A;
        cin >> A;
        num[A]++;
    }

    SORT(num);
    cout << accumulate(num.begin(), num.end() - K, 0LL) << endl;

    return 0;
}
