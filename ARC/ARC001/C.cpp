#include <iostream>
#include <string>
#include <vector>

using namespace std;

// (x, y)と(sx, sy)が縦、横、斜めの同一直線上にあるか判定
bool sameline(int x, int y, int sx, int sy) {
    if (x == sx || y == sy) return true;
    if (abs(x - sx) == abs(y - sy)) return true;
    return false;
}

// x行目にクイーンを置きたい
// 置けなければbrd[0][0]を'X'に書き換えて返す
vector<string> dfs(vector<string> brd, int x) {

    // すでに条件を満たす配置になっている
    if (x == 8) {
        return brd;
    }

    for (int y = 0; y < 8; ++y) {
        // (x, y)にクイーンが置けるか判定
        bool judge = true;

        for (int sx = 0; sx < 8; ++sx) {
            for (int sy = 0; sy < 8; ++sy) {
                if (x == sx && y == sy) continue;
                if (brd[sx][sy] != 'Q') continue;
                judge = (judge && !sameline(x, y, sx, sy));
            }
        }

        if (judge) {
            // 既にクイーンが置かれているかを記録
            bool preq = (brd[x][y] == 'Q');
            brd[x][y] = 'Q';
            auto ret = dfs(brd, x + 1);

            if (ret[0][0] != 'X') return ret;

            // 元々クイーンが置かれていなければ元に戻す
            if (!preq) brd[x][y] = '.';
        }
    }

    // どこにも置けない場合
    brd[0][0] = 'X';
    return brd;
}

int main() {
    vector<string> brd(8);
    for (int x = 0; x < 8; ++x) {
        cin >> brd[x];
    }

    vector<string> ans = dfs(brd, 0);

    if (ans[0][0] == 'X') {
        cout << "No Answer" << endl;
    } else {
        for (int x = 0; x < 8; ++x) {
            cout << ans[x] << endl;
        }
    }
    return 0;
}
