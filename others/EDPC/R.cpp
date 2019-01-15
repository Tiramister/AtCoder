#include <iostream>
#include <map>
#include <tuple>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int N;
ll pat[50][50][61];
// iからjまで距離2^nのパス数
map<tuple<int, int, ll>, ll> dp;

ll route(int i, int j, ll K) {
    if (K == 0) return i == j;
    if (dp.find(make_tuple(i, j, K)) != dp.end()) {
        return dp[make_tuple(i, j, K)];
    }

    ll ret = 0;
    for (int k = 0; k < N; ++k) {
        for (int n = 60; n >= 0; --n) {
            if ((K >> n) & 1) {
                ret += pat[i][k][n] * route(k, j, K - (1LL << n));
                ret %= MOD;
                break;
            }
        }
    }

    dp[make_tuple(i, j, K)] = ret;
    return ret;
}

int main() {
    ll K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> pat[i][j][0];
        }
    }

    for (int n = 1; n <= 60; ++n) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    pat[i][k][n] += pat[i][j][n - 1] * pat[j][k][n - 1];
                    pat[i][k][n] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans += route(i, j, K);
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
