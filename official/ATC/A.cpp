#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    int H, W;
    cin >> H >> W;

    pair<int, int> s;
    string S[H];

    for (int i = 0; i < H; ++i) {
        cin >> S[i];
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == 's') {
                s = make_pair(i, j);
            }
        }
    }

    queue<pair<int, int>> que;
    que.push(s);
    S[s.first][s.second] = '#';

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int sx = x + dx[i];
            int sy = y + dy[i];

            if (sx < 0 || H <= sx || sy < 0 || W <= sy || S[sx][sy] == '#') continue;

            if (S[sx][sy] == 'g') {
                cout << "Yes" << endl;
                return 0;
            }

            S[sx][sy] = '#';
            que.push(make_pair(sx, sy));
        }
    }

    cout << "No" << endl;
    return 0;
}
