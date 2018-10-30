#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 25;

int main() {
    int N;
    cin >> N;

    int cnt[N];
    fill(cnt, cnt + N, 0);
    // 隣接する頂点数
    // ただし白頂点は除外
    // 塗られたものはINF

    vector<int> path[N];

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[--a], ++cnt[--b];
        path[a].push_back(b);
        path[b].push_back(a);
    }

    vector<int> one;
    // cnt[v] = 1なる頂点の集合

    for (int v = 0; v < N; ++v) {
        if (cnt[v] == 1) one.push_back(v);
    }

    // ここから白はリーチを掛けまくる
    while (!one.empty()) {
        int v = one.back();
        one.pop_back();
        if (cnt[v] != 1) continue;

        int w;
        // vに隣接する頂点
        // これを白に塗ることでcnt[v] = 0(リーチ)にする

        for (int sv : path[v]) {
            if (cnt[sv] < INF) w = sv;
        }

        cnt[w] = INF * 2;

        vector<int> zero;
        // cnt[v] = 0なる頂点の集合
        // 黒はこれら全てを塞がなければならない

        for (int sv : path[w]) {
            --cnt[sv];
            if (cnt[sv] == 1) one.push_back(sv);
            if (cnt[sv] == 0) zero.push_back(sv);
        }

        // 黒が1ターンに塞げる頂点は1個なので、
        // 2個以上リーチがあると詰み
        if (zero.size() > 1) {
            cout << "First" << endl;
            return 0;
        }

        // 逆に1個なら黒が塞ぐ
        cnt[zero.back()] = INF * 2;
    }

    // 万策尽きました
    cout << "Second" << endl;
    return 0;
}
