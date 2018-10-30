#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define mp make_pair

const int INF = 1 << 20;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    int H, W, X;
    cin >> H >> W >> X;

    string S[H];
    pair<int, int> s, g;
    vector<pair<int, int>> dan;
    for (int x = 0; x < H; ++x) {
        cin >> S[x];
        for (int y = 0; y < W; ++y) {
            if (S[x][y] == 'S') {
                s = mp(x, y);
            } else if (S[x][y] == 'G') {
                g = mp(x, y);
            } else if (S[x][y] == '@') {
                dan.push_back(mp(x, y));
            }
        }
    }

    int d[H + 1][W];
    fill(d[0], d[H], INF);
    queue<pair<int, int>> que;

    // 危険なマスを埋める
    for (auto p : dan) {
        S[p.first][p.second] = '#';
        d[p.first][p.second] = 0;
        que.push(p);
    }

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        if (d[x][y] >= X) continue;

        for (int i = 0; i < 4; ++i) {
            int sx = x + dx[i];
            int sy = y + dy[i];

            if (S[sx][sy] == '#') continue;

            S[sx][sy] = '#';
            d[sx][sy] = d[x][y] + 1;
            que.push(mp(sx, sy));
        }
    }

    fill(d[0], d[H], INF);

    d[s.first][s.second] = 0;
    que.push(s);

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int sx = x + dx[i];
            int sy = y + dy[i];

            if (S[sx][sy] == '#') continue;

            S[sx][sy] = '#';
            d[sx][sy] = d[x][y] + 1;
            que.push(mp(sx, sy));
        }
    }

    int ans = d[g.first][g.second];
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
