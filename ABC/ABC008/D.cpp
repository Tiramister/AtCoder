#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, X[30], Y[30];
vector<int> coox, cooy;
int dp[40][40][40][40];
bool visited[40][40][40][40];

int rec(int lx, int ly, int ux, int uy) {
    if (ux < lx || uy < ly) return 0;

    if (visited[lx][ly][ux][uy]) return dp[lx][ly][ux][uy];
    visited[lx][ly][ux][uy] = true;

    dp[lx][ly][ux][uy] = 0;
    int cross = (coox[ux] - coox[lx]) + (cooy[uy] - cooy[ly]) - 3;

    for (int i = 0; i < N; ++i) {
        if (X[i] <= lx || ux <= X[i] || Y[i] <= ly || uy <= Y[i]) continue;
        int res = 0;
        res += rec(lx, ly, X[i], Y[i]);
        res += rec(X[i], ly, ux, Y[i]);
        res += rec(lx, Y[i], X[i], uy);
        res += rec(X[i], Y[i], ux, uy);
        dp[lx][ly][ux][uy] = max(dp[lx][ly][ux][uy], res + cross);
    }

    return dp[lx][ly][ux][uy];
}

int main() {
    int H, W;
    cin >> H >> W >> N;

    coox = {-1, H}, cooy = {-1, W};

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
        coox.push_back(--X[i]);
        cooy.push_back(--Y[i]);
    }

    sort(coox.begin(), coox.end());
    coox.erase(unique(coox.begin(), coox.end()), coox.end());

    sort(cooy.begin(), cooy.end());
    coox.erase(unique(cooy.begin(), cooy.end()), cooy.end());

    for (int i = 0; i < N; ++i) {
        for (int x = 0; x < coox.size(); ++x) {
            if (coox[x] == X[i]) {
                X[i] = x;
                break;
            }
        }
        for (int y = 0; y < coox.size(); ++y) {
            if (cooy[y] == Y[i]) {
                Y[i] = y;
                break;
            }
        }
    }

    cout << rec(0, 0, coox.size() - 1, cooy.size() - 1) << endl;
    return 0;
}
