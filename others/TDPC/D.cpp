#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int c[7][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {2, 0, 0},
    {0, 0, 1},
    {1, 1, 0},
};

vector<int> div235(ll D) {
    const ll d[3] = {2, 3, 5};
    vector<int> A(3, 0);

    for (int i = 0; i < 3; ++i) {
        while (D % d[i] == 0) {
            D /= d[i];
            ++A[i];
        }
    }

    if (D > 1) A[0] = -1;
    return A;
}


int main() {
    int N;
    ll D;
    cin >> N >> D;

    vector<int> A = div235(D);
    if (A[0] < 0) {
        cout << 0 << endl;
        return 0;
    }

    double dp[A[0] + 1][A[1] + 1][A[2] + 1];
    fill(dp[0][0], dp[A[0] + 1][0], 0);
    dp[0][0][0] = 1;
    // dp[i][j][k] = n回サイコロを振った積が
    //               2^i 3^j 5^kの倍数である確率

    for (int n = 0; n < N; ++n) {
        double ndp[A[0] + 1][A[1] + 1][A[2] + 1];
        fill(ndp[0][0], ndp[A[0] + 1][0], 0);

        for (int i = 0; i <= A[0]; ++i) {
            for (int j = 0; j <= A[1]; ++j) {
                for (int k = 0; k <= A[2]; ++k) {
                    for (int d = 1; d <= 6; ++d) {
                        int si = min(A[0], i + c[d][0]);
                        int sj = min(A[1], j + c[d][1]);
                        int sk = min(A[2], k + c[d][2]);
                        ndp[si][sj][sk] += dp[i][j][k] / 6;
                    }
                }
            }
        }

        for (int i = 0; i <= A[0]; ++i) {
            for (int j = 0; j <= A[1]; ++j) {
                for (int k = 0; k <= A[2]; ++k) {
                    dp[i][j][k] = ndp[i][j][k];
                }
            }
        }
    }

    cout << fixed << setprecision(10) << dp[A[0]][A[1]][A[2]] << endl;
    return 0;
}
