#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    --K;
    // 以降縦棒の番号は0-indexedで扱う

    ll dp[H + 1][W];
    fill(dp[0], dp[H + 1], 0);
    dp[0][0] = 1;
    // dp[h][k] = 横線h段からなるあみだくじで、0がkに来るものの数

    for (int h = 0; h < H; ++h) {
        for (int b = 0; b < (1 << (W - 1)); ++b) {

            // 横線が隣り合っていないかチェック
            bool judge = true;
            for (int i = 0; i < W - 2; ++i) {
                // これで末尾が11のときに弾くことができる
                if ((b >> i) % 4 == 3) judge = false;
            }

            if (!judge) continue;

            // 各始点がどこへ移動するか求める
            int perm[W];
            for (int i = 0; i < W; ++i)
                perm[i] = i;

            for (int i = 0; i < W - 1; ++i) {
                // あみだくじのルールに従って位置をswap
                if ((b >> i) & 1) swap(perm[i], perm[i + 1]);
            }

            // 配る
            for (int i = 0; i < W; ++i) {
                dp[h + 1][perm[i]] += dp[h][i];
                dp[h + 1][perm[i]] %= MOD;
            }
        }
    }

    cout << dp[H][K] << endl;
    return 0;
}
