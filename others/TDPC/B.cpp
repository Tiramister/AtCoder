#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int a[A + 1], b[B + 1];
    for (int i = A; i >= 1; --i) {
        cin >> a[i];
    }
    for (int j = B; j >= 1; --j) {
        cin >> b[j];
    }

    pair<int, int> dp[A + 1][B + 1];
    dp[0][0] = make_pair(0, 0);
    // dp[i][j] = 山が(i, j)残っているときの最善策

    // dp[i][0]を埋める
    for (int i = 1; i <= A; ++i) {
        auto p = dp[i - 1][0];
        dp[i][0] = make_pair(p.second + a[i], p.first);
    }

    // dp[0][j]を埋める
    for (int j = 1; j <= B; ++j) {
        auto p = dp[0][j - 1];
        dp[0][j] = make_pair(p.second + b[j], p.first);
    }

    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            auto p = dp[i - 1][j];
            p = make_pair(p.second + a[i], p.first);

            auto q = dp[i][j - 1];
            q = make_pair(q.second + b[j], q.first);

            dp[i][j] = max(p, q);
        }
    }

    cout << dp[A][B].first << endl;
    return 0;
}
