#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

ll f(int k, ll a) {
    if (k == 2) {  // 奇数の区間
        return (a + 1) % 2;
    } else if (1 <= k && k <= 3) {  // 偶数の区間
        return (a == 0 ? 2 : a % 2);
    } else {  // 無の区間
        return a;
    }
}

int main() {
    int N;
    cin >> N;
    ll a[N + 2];
    for (int i = 1; i <= N; ++i) cin >> a[i];
    a[N + 1] = 0;

    ll dp[N + 2][5];
    fill(dp[0], dp[1], 0);
    fill(dp[1], dp[N + 2], INF);

    for (int i = 1; i <= N + 1; ++i) {
        for (int k = 0; k < 5; ++k) {
            ll m = *min_element(dp[i - 1], dp[i - 1] + k + 1);
            dp[i][k] = m + f(k, a[i]);
        }
    }

    cout << dp[N + 1][4] << endl;
    return 0;
}
