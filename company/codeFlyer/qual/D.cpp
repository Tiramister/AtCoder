#include <iostream>
#include <string>
using namespace std;
using ll = long long;

ll imos[2100][2100];

int main() {
    ll H, W, N, M;
    cin >> H >> W >> N >> M;

    string A[N];
    for (ll x = 0; x < N; ++x) {
        cin >> A[x];
    }

    // H, Wがめっちゃ大きいときは2001*2001に圧縮
    // この盤面にimos法を適用する
    ll X = min(H, 2001LL);
    ll Y = min(W, 2001LL);
    ll dx = X - N + 1, dy = Y - M + 1;

    fill(imos[0], imos[2050], 0);

    // マーキング
    for (ll x = 0; x < N; ++x) {
        for (ll y = 0; y < M; ++y) {
            if (A[x][y] == '.') continue;
            ++imos[x][y];
            --imos[x + dx][y];
            --imos[x][y + dy];
            ++imos[x + dx][y + dy];
        }
    }

    // 横方向に展開
    for (ll x = 0; x < X; ++x) {
        for (ll y = 1; y < Y; ++y) {
            imos[x][y] += imos[x][y - 1];
        }
    }

    // 縦方向に展開
    for (ll x = 1; x < X; ++x) {
        for (ll y = 0; y < Y; ++y) {
            imos[x][y] += imos[x - 1][y];
        }
    }

    // 0と1に正規化(?)
    for (ll x = 0; x < X; ++x) {
        for (ll y = 0; y < Y; ++y) {
            imos[x][y] = (imos[x][y] > 0);
        }
    }

    // 横方向に圧縮した分を還元
    if (W > 2001) {
        for (ll x = 0; x < X; ++x) {
            imos[x][1000] *= (W - 2000);
        }
    }

    // 縦方向に圧縮した分を還元
    if (H > 2001) {
        for (ll y = 0; y < Y; ++y) {
            imos[1000][y] *= (H - 2000);
        }
    }

    // 集計
    ll ans = 0;
    for (ll x = 0; x < X; ++x) {
        for (ll y = 0; y < Y; ++y) {
            ans += imos[x][y];
        }
    }

    cout << ans << endl;
    return 0;
}
