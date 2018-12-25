#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll a, b, x;
        cin >> a >> b >> x;

        ll fib[88];
        fib[0] = a, fib[1] = b;
        for (int i = 2; i < 88; ++i) {
            fib[i] = min(fib[i - 1] + fib[i - 2], x + 1);
        }

        vector<map<ll, ll>> dp(88);
        dp[0][a] = 1;
        dp[1][b] = 1;

        for (int i = 2; i < 88; ++i) {
            if (fib[i] <= x) {
                dp[i][fib[i]] = 1;
            }

            for (int j = 0; j < i - 1; ++j) {
                for (auto p : dp[j]) {
                    ll c = p.first + fib[i];
                    if (c > x) continue;
                    if (dp[i].find(c) == dp[i].end()) dp[i][c] = 0;
                    dp[i][c] += p.second;
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < 88; ++i) {
            if (dp[i].find(x) != dp[i].end()) ans += dp[i][x];
        }

        cout << ans << endl;
    }
    return 0;
}
