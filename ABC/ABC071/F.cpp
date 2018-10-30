#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string S[H];
    for (int x = 0; x < H; ++x) {
        cin >> S[x];
    }

    int pat[H - 1][W];
    for (int x = 0; x < H - 1; ++x) {
        for (int y = 0; y < W - 1; ++y) {
            int cnt = 0;
            for (int i = x; i <= x + 1; ++i) {
                for (int j = y; j <= y + 1; ++j) {
                    cnt += (S[i][j] == '#');
                }
            }
            pat[x][y] = 1 - cnt % 2;
        }
        pat[x][W - 1] = 0;
    }

    for (int x = 1; x < H - 1; ++x) {
        for (int y = 0; y < W; ++y) {
            if (pat[x][y] > 0) pat[x][y] += pat[x - 1][y];
        }
    }

    int ans = max(H, W);

    for (int x = 0; x < H - 1; ++x) {
        vector<pair<int, int>> recs;
        for (int y = 0; y < W; ++y) {
            if (recs.empty() || recs.back().second < pat[x][y]) {
                recs.push_back(make_pair(y, pat[x][y]));

            } else if (recs.back().second > pat[x][y]) {
                auto pre = recs.back();

                while (!recs.empty() && recs.back().second > pat[x][y]) {
                    auto p = recs.back();
                    recs.pop_back();
                    int S = (y - p.first + 1) * (p.second + 1);
                    ans = max(ans, S);
                    pre = p;
                }

                if (recs.empty() || recs.back().second < pat[x][y]) {
                    recs.push_back(make_pair(pre.first, pat[x][y]));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
