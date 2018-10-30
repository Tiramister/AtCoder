#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
const ll INF = 1LL << 50;

struct edge {
    ll to;
    ll cap;
    ll rev;  // path[to]中でのfromのイテレータ
    edge(ll to_, ll cap_, ll rev_) : to(to_), cap(cap_), rev(rev_){};
};

class Dinic {
public:
    vector<vector<edge>> path;
    vector<ll> level, iter;

    explicit Dinic(ll N) {
        path.resize(N);
        level.resize(N);
        iter.resize(N);
    }

    void add_edge(ll from, ll to, ll cap) {
        // fromとtoの間に双方向の辺を加える
        // 有向の場合は後者のcapを0にする
        path[from].push_back(edge(to, cap, path[to].size()));
        path[to].push_back(edge(from, 0, path[from].size() - 1));
    }

    void bfs(ll s) {
        // 頂点sからのcap>0の辺のみを通った最短距離を求める
        // 辿り着けなければ-1

        fill(level.begin(), level.end(), -1);
        queue<ll> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();

            for (auto e : path[v]) {
                ll sv = e.to, c = e.cap;
                if (c > 0 && level[sv] < 0) {
                    level[sv] = level[v] + 1;
                    que.push(sv);
                }
            }
        }
    }

    ll dfs(ll v, ll g, ll f) {
        if (v == g) return f;

        // iterで事前にどこまで探索したかをセーブ
        for (ll& itr = iter[v]; itr < path[v].size(); ++itr) {
            edge e = path[v][itr];

            if (e.cap > 0 && level[v] < level[e.to]) {
                ll df = dfs(e.to, g, min(f, e.cap));
                if (df > 0) {
                    path[v][itr].cap -= df;
                    path[e.to][e.rev].cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    ll max_flow(ll s, ll g) {
        // sからgへの最大フロー(最小カット)を求める

        ll flow = 0;
        while (true) {
            bfs(s);
            if (level[g] < 0) {
                return flow;
            }
            fill(iter.begin(), iter.end(), 0);
            ll f;
            while (true) {
                f = dfs(s, g, INF);
                if (f == 0) break;
                flow += f;
            }
        }
    }
};


int main() {
    int r, c;
    cin >> r >> c;

    string S[r];
    for (int x = 0; x < r; ++x) {
        cin >> S[x];
    }

    Dinic dinic(r * c + 2);
    int cnt = 0;
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (S[x][y] == '*') continue;
            ++cnt;
            if ((x + y) % 2 == 0) {
                dinic.add_edge(r * c, x * c + y, 1);
            } else {
                dinic.add_edge(x * c + y, r * c + 1, 1);
            }
        }
    }

    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if ((x + y) % 2 > 0 || S[x][y] != '.') continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < r && 0 <= ny && ny < c && S[nx][ny] == '.') {
                    dinic.add_edge(x * c + y, nx * c + ny, 1);
                }
            }
        }
    }

    cout << cnt - dinic.max_flow(r * c, r * c + 1) << endl;

    return 0;
}
