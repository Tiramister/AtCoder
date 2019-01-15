#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    ll pat[N + 1][K + 1];
    ll sum[N + 1][K];
    fill(pat[0], pat[1], 0);
    pat[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        sum[i - 1][0] = pat[i - 1][0];
        for (int k = 1; k <= K; ++k) {
            sum[i - 1][k] = (sum[i - 1][k - 1] + pat[i - 1][k]) % MOD;
        }

        fill(pat[i], pat[i + 1], 0);

        int a;
        cin >> a;

        for (int k = 0; k <= K; ++k) {
            pat[i][k] += sum[i - 1][k] - (k > a ? sum[i - 1][k - a - 1] : 0) + MOD;
            pat[i][k] %= MOD;
        }
    }

    cout << pat[N][K] << endl;
    return 0;
}
