#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll dp[41][2];
    for (int m = 0; m <= 40; ++m) {
        ll score[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            score[1 - ((a[i] >> m) & 1)] += (1LL << m);
        }

        dp[m][0] = max(score[0], score[1]) + (m == 0 ? 0 : dp[m - 1][0]);
        if ((k >> m) & 1) {
            dp[m][1] = max(score[0] + (m == 0 ? 0 : dp[m - 1][0]),
                           score[1] + (m == 0 ? 0 : dp[m - 1][1]));
        } else {
            dp[m][1] = score[0] + (m == 0 ? 0 : dp[m - 1][1]);
        }
    }

    cout << dp[40][1] << endl;
}
