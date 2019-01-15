#include <iostream>
#include <string>
using namespace std;
const int INF = 1 << 25;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    string T = "yahoo";

    int dp[N + 1][5];
    for (int j = 0; j < 5; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= N; ++i) {
        fill(dp[i], dp[i] + 5, INF);

        for (int j = 0; j <= 10; ++j) {
            dp[i][j % 5] =
                min(
                    min(dp[i - 1][j % 5] + 1,
                        dp[i][(j + 4) % 5] + 1),
                    dp[i - 1][(j + 4) % 5] + (S[i - 1] != T[(j + 4) % 5]));
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}
