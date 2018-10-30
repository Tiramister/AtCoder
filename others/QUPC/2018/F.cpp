#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll dp[1 << N];
    fill(dp, dp + (1 << N), 0);
    dp[0] = 1;
    // dp[S] = Sの人達をグループに分けるパターン数

    for (int b = 0; b < (1 << N); ++b) {
        // まだグループに入ってない最初の人だけに注目
        for (int i = 0; i < N; ++i) {
            if ((b >> i) & 1) continue;

            // 1人でグループを作る場合
            dp[b | (1 << i)] += dp[b];

            // 2人
            for (int j = i + 1; j < N; ++j) {
                int pat = (1 << i) + (1 << j);
                if ((b & pat) > 0 || A[i] + A[j] > K * 2) continue;
                dp[b | pat] += dp[b];
            }

            // 3人
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    int pat = (1 << i) + (1 << j) + (1 << k);
                    if ((b & pat) > 0 || A[i] + A[j] + A[k] > K * 3) continue;
                    dp[b | pat] += dp[b];
                }
            }
            break;
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
