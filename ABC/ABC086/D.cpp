#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int x[N], y[N], c[N];

    // まずは2K * 2Kの範囲に絞る
    for (int i = 0; i < N; ++i) {
        char sc;
        cin >> x[i] >> y[i] >> sc;
        x[i] %= K * 2;
        y[i] %= K * 2;
        c[i] = (sc == 'W');
    }

    int white[K][K];
    fill(white[0], white[K], 0);
    // while[x][y] = マス(x, y)を右上とした長方形に
    //               含まれている(白マス-黒マス)の総数

    int bnum = 0;
    // 黒マスを指定する条件の数

    // K * Kの範囲に絞る
    // 座標をKで割った値の偶奇で色が変わる
    for (int i = 0; i < N; ++i) {
        c[i] += x[i] / K + y[i] / K;
        c[i] %= 2;
        x[i] %= K;
        y[i] %= K;
        white[x[i]][y[i]] += (c[i] ? 1 : -1);
        if (c[i] == 0) ++bnum;
    }

    // 2次元imosの要領で展開
    for (int x = 0; x < K; ++x) {
        for (int y = 1; y < K; ++y) {
            white[x][y] += white[x][y - 1];
        }
    }

    for (int x = 1; x < K; ++x) {
        for (int y = 0; y < K; ++y) {
            white[x][y] += white[x - 1][y];
        }
    }

    int ans = 0;
    for (int x = 0; x < K; ++x) {
        for (int y = 0; y < K; ++y) {
            // (x, y)を右上の頂点とした長方形を白く塗るパターン
            int w = white[K - 1][K - 1] - white[x][K - 1] - white[K - 1][y] + white[x][y] * 2 + bnum;

            ans = max(ans, max(w, N - w));
        }
    }

    cout << ans << endl;
    return 0;
}
