#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    bool m[H][W];
    for (int x = 0; x < H; ++x) {
        string S;
        cin >> S;
        for (int y = 0; y < W; ++y) {
            m[x][y] = (S[y] == 'S');
        }
    }

    // 初期状態における対称性を求める
    bool ajudge = true, bjudge = true;
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (m[x][y] != m[H - x - 1][y]) ajudge = false;
            if (m[x][y] != m[x][W - y - 1]) bjudge = false;
        }
    }

    int ans = 0;
    if (!ajudge) ans += A;
    if (!bjudge) ans += B;

    // ゴミを撤去する
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (!m[H - x - 1][y] && !m[x][W - y - 1]) m[x][y] = false;
        }
    }

    // 上下左右対称なものをスコアに加算して取り除く
    for (int x = 0; x < H / 2; ++x) {
        for (int y = 0; y < W / 2; ++y) {
            if (m[x][y] && m[H - x - 1][y] &&
                m[x][W - y - 1] && m[H - x - 1][W - y - 1]) {
                ans += A + B + max(A, B);
                m[x][y] = m[H - x - 1][y] =
                    m[x][W - y - 1] = m[H - x - 1][W - y - 1] = false;
            }
        }
    }

    // 上下対称、左右対称な組をそれぞれ数える
    // 重複して数えていることに注意
    int a = 0, b = 0;
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            a += (m[x][y] && m[H - x - 1][y]);
            b += (m[x][y] && m[x][W - y - 1]);
        }
    }
    a /= 2, b /= 2;

    // そのうちよりスコアが稼げる方のみを加算
    ans += max(A * a, B * b);

    cout << ans << endl;
    return 0;
}
