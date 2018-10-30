#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

template <typename T>
class Queue {
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

    T front() {
        return pulled.front();
    }

    int size() {
        return pulled.size() + pushed.size();
    }

    bool empty() {
        return size() == 0;
    }
};

const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};

int main() {
    int H, W;
    cin >> H >> W;

    string S[H];
    int bnum = 0;
    for (int h = 0; h < H; ++h) {
        cin >> S[h];
        for (int w = 0; w < W; ++w) {
            if (S[h][w] == '#') ++bnum;
        }
    }

    int d[H][W];
    fill(d[0], d[H], -1);

    Queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    d[0][0] = 1;

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.pop();

        for (int i = 0; i < 4; ++i) {
            int sx = x + dx[i];
            int sy = y + dy[i];
            if (0 <= sx && sx < H && 0 <= sy && sy < W && S[sx][sy] == '.' && d[sx][sy] < 0) {
                d[sx][sy] = d[x][y] + 1;
                que.push(make_pair(sx, sy));
            }
        }
    }

    cout << (d[H - 1][W - 1] < 0 ? -1 : H * W - bnum - d[H - 1][W - 1]) << endl;
    return 0;
}
