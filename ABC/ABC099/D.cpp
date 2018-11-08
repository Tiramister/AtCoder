#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N, C;
    cin >> N >> C;

    int D[C][C];
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> D[i][j];
        }
    }

    int cl[N][N];
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            cin >> cl[x][y];
            --cl[x][y];
        }
    }

    int diff[3][C];
    fill(diff[0], diff[3], 0);
    // ゾーンiをcに変えるときの違和感

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            for (int c = 0; c < C; ++c) {
                if (cl[x][y] == c) continue;
                diff[(x + y) % 3][c] += D[cl[x][y]][c];
            }
        }
    }

    int ans = INF;
    int a[3];
    // ゾーンiをa[i]で塗る

    for (a[0] = 0; a[0] < C; ++a[0]) {
        for (a[1] = 0; a[1] < C; ++a[1]) {
            for (a[2] = 0; a[2] < C; ++a[2]) {
                // a[i]間に重複がないか判定
                bool dup = false;
                for (int i = 0; i < 3; ++i) {
                    if (a[i] == a[(i + 1) % 3]) dup = true;
                }
                if (dup) continue;

                int cost = 0;
                for (int i = 0; i < 3; ++i) {
                    cost += diff[i][a[i]];
                }

                ans = min(ans, cost);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
