#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int INF = 1 << 20;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

struct coo {
    int x;
    int y;
};

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    string S[H];
    coo s;
    for (int x = 0; x < H; ++x) {
        cin >> S[x];
        for (int y = 0; y < W; ++y) {
            if (S[x][y] == 'S') {
                s = {x, y};
            }
        }
    }

    int d[H][W];
    fill(d[0], d[H], INF);

    queue<coo> que;
    que.push(s);
    d[s.x][s.y] = 0;

    // 壁を避けてK回移動
    while (!que.empty()) {
        coo v = que.front();
        que.pop();

        // K回以内で出られる場合
        if (v.x == 0 || v.x == H - 1 || v.y == 0 || v.y == W - 1) {
            cout << 1 << endl;
            return 0;
        }

        if (d[v.x][v.y] == K) continue;

        for (int i = 0; i < 4; ++i) {
            coo sv = {v.x + dx[i], v.y + dy[i]};

            // 境界外なら上で弾かれている
            if (S[sv.x][sv.y] == '#' || d[sv.x][sv.y] < INF) continue;

            d[sv.x][sv.y] = d[v.x][v.y] + 1;
            que.push(sv);
        }
    }

    // 外までの最短距離
    // ここまで来たら壁ガン無視でOK
    int mi = INF;
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (d[x][y] == INF) continue;
            mi = min(mi, min(x, H - x - 1));
            mi = min(mi, min(y, W - y - 1));
        }
    }

    cout << (mi + K - 1) / K + 1 << endl;
    return 0;
}
