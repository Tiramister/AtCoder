#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll fib_t[1000];

ll fib(int n) {
    if (n < 0) return 1;
    if (fib_t[n] > 0) return fib_t[n];
    return fib_t[n] = (fib(n - 1) + fib(n - 2)) % MOD;
}

// 行列の積(正方行列を仮定)
vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
    int l = a[0].size();

    vector<vector<ll>> ret(l, vector<ll>(l, 0));

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            for (int k = 0; k < l; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

// ダブリングによる行列累乗
vector<vector<ll>> matpow(vector<vector<ll>> m, int n) {
    int l = m[0].size();

    // 単位行列を返す
    if (n == 0) {
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                m[i][j] = (i == j);
            }
        }
        return m;
    }

    if (n == 1) return m;

    if (n % 2) {
        return matmul(matpow(m, n - 1), m);
    } else {
        auto half = matpow(m, n / 2);
        return matmul(half, half);
    }
}

int main() {
    fib_t[0] = 1, fib_t[1] = 1;

    int H, W, K;
    cin >> H >> W >> K;
    --K;
    // 以降縦棒の番号は0-indexedで扱う

    vector<vector<ll>> pat(W, vector<ll>(W, 0));

    // 左に移動するパターン
    for (int i = 1; i < W; ++i) {
        pat[i - 1][i] = fib(i - 1) * fib(W - i - 1) % MOD;
    }

    // 右に移動するパターン
    for (int i = 0; i < W - 1; ++i) {
        pat[i + 1][i] = fib(i) * fib(W - i - 2) % MOD;
    }

    // 真下に移動するパターン
    for (int i = 0; i < W; ++i) {
        pat[i][i] = fib(i) * fib(W - i - 1) % MOD;
    }

    auto res = matpow(pat, H);

    cout << res[K][0] << endl;

    return 0;
}
