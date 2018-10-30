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
// const int INF = 1e9;
const ll INF = 4e18;
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
    int N, K;
    cin >> N >> K;

    vector<ll> x(N), y(N);
    REP(i, N)
    {
        cin >> x[i] >> y[i];
    }

    ll area_min = INF;

    REP(ix, N)
    {
        REP(jx, N)
        {
            if (x[ix] >= x[jx]) {
                continue;
            }

            REP(iy, N)
            {
                REP(jy, N)
                {
                    if (y[iy] >= y[jy]) {
                        continue;
                    }


                    int cnt = 0;

                    REP(k, N)
                    {
                        if (x[ix] <= x[k] && x[jx] >= x[k] && y[iy] <= y[k] && y[jy] >= y[k])
                            cnt++;
                    }

                    if (cnt >= K) {
                        ll area = (x[jx] - x[ix]) * (y[jy] - y[iy]);
                        if (area_min > area) {
                            area_min = area;
                            // cout << x[ix] << " " << x[jx] << " " << y[iy] << " " << y[jy] << endl;
                        }
                    }
                }
            }
        }
    }

    cout << area_min << endl;

    return 0;
}
