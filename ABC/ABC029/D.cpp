#include <iostream>

using namespace std;
using ll = long long;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        return mypow(b * b, n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

int main() {
    int n;
    cin >> n;

    ll dp[11][2];
    fill(dp[0], dp[11], 0);
    for (int m = 0; m <= 10; ++m) {
        dp[m][0] = (m == 0 ? 0 : dp[m - 1][0]) * 10 + mypow(10LL, m);

        int p = n / mypow(10LL, m) % 10;
        dp[m][1] = (m == 0 ? 0 : dp[m - 1][0]) * p;
        if (p > 1) dp[m][1] += mypow(10LL, m);

        dp[m][1] += (m == 0 ? 0 : dp[m - 1][1]);
        if (p == 1) dp[m][1] += n % mypow(10LL, m) + 1;
    }

    cout << dp[10][1] << endl;
    return 0;
}
