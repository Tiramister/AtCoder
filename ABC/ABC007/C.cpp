#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

template <typename T>
class queue {
private:
    vector<T> pulled, pushed;

public:
    void push(T a) {
        pushed.push_back(a);
    }

    T pop() {
        if (pulled.empty()) {
            reverse(pushed.begin(), pushed.end());
            pulled = pushed;
            pushed.clear();
        }
        T top = pulled.back();
        pulled.pop_back();
        return top;
    }

    T top() {
        return pulled.back();
    }

    bool empty() {
        return pulled.empty() && pushed.empty();
    }
};

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    int R, C, sx, sy, gx, gy;
    cin >> R >> C >> sx >> sy >> gx >> gy;
    --sx;
    --sy;
    --gx;
    --gy;

    string S[R];
    for (int i = 0; i < R; ++i) {
        cin >> S[i];
    }

    int d[R][C];
    fill(d[0], d[R], -1);
    d[sx][sy] = 0;

    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (S[nx][ny] == '#' || d[nx][ny] >= 0) continue;
            d[nx][ny] = d[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }

    cout << d[gx][gy] << endl;
    return 0;
}
