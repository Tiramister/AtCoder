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

// namespace
using namespace std;

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;

// conversion
#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)

// container
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define GSORT(c) sort((c).begin(), (c).end(), greater<decltype((c).front())>())
#define SZ(x) (INT((x).size()))
#define MEMSET(c, v) memset((c), v, sizeof(c))

// repetition
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// constant
const ll MOD = 1e9 + 7;
// const int INF = 1<<25;
// const ll INF = 1LL<<50;
// const int dx[4] = {0, -1, 1, 0};
// const int dy[4] = {-1, 0, 0, 1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// debug
#define test(x) cout << #x << " = " << x << endl

// answer output
#define Yes(c) cout << ((c) ? "Yes" : "No") << endl;
#define YES(c) cout << ((c) ? "YES" : "NO") << endl;
#define yes(c) cout << ((c) ? "yes" : "no") << endl;

#define possible(c) cout << ((c) ? "possible" : "impossible") << endl;
#define POSSIBLE(c) cout << ((c) ? "POSSIBLE" : "INPOSSIBLE") << endl;


// --------------------------------------------------------

VVL powdp(401, VL(401));

void calc_pow() {
    REP(i, 401) {
        powdp[i][0] = 1;
    }

    NREP(j, 400) {
        REP(i, 401) {
            powdp[i][j] = powdp[i][j - 1] * i;
            powdp[i][j] %= MOD;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    calc_pow();

    ll N, C;
    cin >> N >> C;
    VL A(N + 1), B(N + 1);
    NREP(i, N) {
        cin >> A[i];
    }
    NREP(i, N) {
        cin >> B[i];
    }

    VVL dp(N + 1, VL(C + 1, 0));

    dp[0][0] = 1;
    NREP(j, C) {
        dp[0][j] = 0;
    }

    NREP(i, N) {
        REP(k, C + 1) {
            ll powAB = 0;
            FOR(n, A[i], B[i] + 1) {
                powAB += powdp[n][k];
                powAB %= MOD;
            }
            // powAB = A[i]^k + A[i+1]^k + ... + B[i]^k

            REP(j, C - k + 1) {
                dp[i][C - j] += dp[i - 1][C - j - k] * powAB % MOD;
                dp[i][C - j] %= MOD;
            }
        }
    }

    cout << dp[N][C] << endl;
    return 0;
}
