#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

template <typename T>
class SmallBinaryHeap {
private:
    vector<T> val;

public:
    void push(T a) {
        int id = val.size();
        val.push_back(a);

        // 親がより大きければswap
        while (id > 0) {
            if (val[(id - 1) / 2] > val[id]) {
                swap(val[(id - 1) / 2], val[id]);
            } else {
                break;
            }
            id = (id - 1) / 2;
        }
    }

    T top() {
        return val.front();
    }

    T pop() {
        T ret = val.front();
        val.front() = val.back();
        val.pop_back();
        int id = 0;

        // 子がより小さければswap
        while (id * 2 + 1 < val.size()) {
            int ch = id * 2 + 1;
            // より小さい子を選ぶ
            if (ch + 1 < val.size() && val[ch] > val[ch + 1]) {
                ++ch;
            }

            if (val[ch] < val[id]) {
                swap(val[ch], val[id]);
            } else {
                break;
            }
            id = ch;
        }
        return ret;
    }

    int size() {
        return val.size();
    }

    bool empty() {
        return val.empty();
    }
};


const int INF = (1 << 30);
vector<pair<int, int>> path[310];

int dijk(int s) {
    int d[310];
    fill(d, d + 310, INF);
    SmallBinaryHeap<pair<int, int>> que;
    que.push(make_pair(0, s));

    while (!que.empty()) {
        int c, v;
        tie(c, v) = que.pop();
        if (d[v] <= c) continue;

        d[v] = c;
        if (v == 1) return d[v];

        for (auto p : path[v]) {
            int sv, sc;
            tie(sv, sc) = p;
            if (v == s && sv == 1) continue;
            que.push(make_pair(d[v] + sc, sv));
        }
    }
    return INF;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        path[u].push_back(make_pair(v, l));
        path[v].push_back(make_pair(u, l));
    }

    int ans = INF;
    for (auto p : path[1]) {
        ans = min(ans, dijk(p.first) + p.second);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
