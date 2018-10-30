#include <cmath>
#include <iostream>
using namespace std;

const int INF = 1 << 25;

int dp[4010][1000];

int main() {
    int R, G, B;
    cin >> R >> G >> B;

    // 全体を正方向に2000移動
    fill(dp[0], dp[1], INF);
    dp[0][0] = 0;

    for (int x = 1; x <= 4000; ++x) {
        // 置かない場合
        for (int n = 0; n <= R + G + B; ++n) {
            dp[x][n] = dp[x - 1][n];
        }

        // 置く場合
        for (int n = 0; n < R + G + B; ++n) {
            int cost = 0;
            if (n < R) {
                cost = abs(x - 900);
            } else if (n < R + G) {
                cost = abs(x - 1000);
            } else {
                cost = abs(x - 1100);
            }
            dp[x][n + 1] = min(dp[x][n + 1], dp[x - 1][n] + cost);
        }
    }

    cout << dp[4000][R + G + B] << endl;
    return 0;
}
