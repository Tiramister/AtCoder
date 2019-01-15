#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int H, W;

map<vector<int>, int> bfs(vector<int> c) {
    map<vector<int>, int> d;
    d[c] = 0;

    queue<vector<int>> que;
    que.push(c);
    while (!que.empty()) {
        c = que.front();
        que.pop();
        if (d[c] >= 12) continue;

        int z = 0;
        for (int x = 0; x < H * W; ++x) {
            if (c[x] == 0) {
                z = x;
                break;
            }
        }

        auto nc = c;
        if (z >= W) {
            swap(nc[z], nc[z - W]);
            if (d.find(nc) == d.end()) {
                d[nc] = d[c] + 1;
                que.push(nc);
            }
        }

        nc = c;
        if (z < H * W - W) {
            swap(nc[z], nc[z + W]);
            if (d.find(nc) == d.end()) {
                d[nc] = d[c] + 1;
                que.push(nc);
            }
        }

        nc = c;
        if (z % W > 0) {
            swap(nc[z], nc[z - 1]);
            if (d.find(nc) == d.end()) {
                d[nc] = d[c] + 1;
                que.push(nc);
            }
        }

        nc = c;
        if (z % W < W - 1) {
            swap(nc[z], nc[z + 1]);
            if (d.find(nc) == d.end()) {
                d[nc] = d[c] + 1;
                que.push(nc);
            }
        }
    }

    return d;
}

int main() {
    cin >> H >> W;

    vector<int> c(H * W);
    for (int x = 0; x < H * W; ++x) {
        cin >> c[x];
    }
    map<vector<int>, int> fore = bfs(c);

    for (int x = 0; x < H * W; ++x) {
        c[x] = x + 1;
    }
    c[H * W - 1] = 0;
    map<vector<int>, int> back = bfs(c);

    int ans = 30;
    for (auto p : fore) {
        if (back.find(p.first) != back.end()) {
            ans = min(ans, p.second + back[p.first]);
        }
    }

    cout << ans << endl;
    return 0;
}
