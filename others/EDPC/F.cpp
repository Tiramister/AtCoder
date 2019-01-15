#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();

    int len[N + 1][M + 1];
    pair<int, int> rev[N + 1][M + 1];
    fill(len[0], len[1], 0);
    for (int i = 0; i <= M; ++i) {
        rev[0][i] = make_pair(0, i - 1);
    }

    for (int i = 1; i <= N; ++i) {
        len[i][0] = 0;
        rev[i][0] = make_pair(i - 1, 0);
        for (int j = 1; j <= M; ++j) {
            if (S[i - 1] == T[j - 1]) {
                len[i][j] = len[i - 1][j - 1] + 1;
                rev[i][j] = make_pair(i - 1, j - 1);
            } else {
                len[i][j] = max(len[i - 1][j], len[i][j - 1]);
                if (len[i - 1][j] > len[i][j - 1]) {
                    rev[i][j] = make_pair(i - 1, j);
                } else {
                    rev[i][j] = make_pair(i, j - 1);
                }
            }
        }
    }

    int x = N, y = M;
    string ans;
    while (x > 0 && y > 0) {
        if (S[x - 1] == T[y - 1]) {
            ans.insert(ans.begin(), S[x - 1]);
        }
        tie(x, y) = rev[x][y];
    }
    cout << ans << endl;
    return 0;
}
