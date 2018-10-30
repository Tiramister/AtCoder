#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 25;

class Segtree {
public:
    explicit Segtree(int N) : V_NUM(1) {
        while (V_NUM < N) {
            V_NUM *= 2;
        }

        data.resize(V_NUM * 2);
        fill(data.begin(), data.end(), INF);
    }

    // 内部処理
    // kは節点のindex、[l, r)がその対応区間
    int query(int a, int b, int k, int l, int r) {
        // [a, b)と[l, r)が交わらない場合
        if (r <= a || b <= l) return INF;

        // [a, b)が[l, r)を包含する場合
        if (a <= l && r <= b) return data[k];

        // 他の場合
        // [l, r)を子に分割する
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    // 外部呼び出し
    // [a, b)の最小値を求める
    int query(int a, int b) {
        return query(a, b, 0, 0, V_NUM);
    }

    // 値の更新
    void update(int i, int v) {
        i += V_NUM - 1;
        data[i] = min(data[i], v);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    int V_NUM;
    vector<int> data;
};


vector<int> l[200020], r[200020];

int main() {
    string S;
    cin >> S;

    int N = S.size();
    Segtree seg(N + 10);

    int h = 100000;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && S[i - 1] == S[i]) {
            h += (S[i] == '(' ? 1 : -1);
        }

        if (S[i] == '(') {
            l[h].push_back(i);
        } else {
            r[h].push_back(i);
        }
        seg.update(i, h);
    }

    int ans = 0;

    for (int i = 0; i < 200010; ++i) {
        if (l[i].empty() || r[i].empty()) continue;

        for (int L : l[i]) {
            int ng = -1, ok = r[i].size();
            while (ok - ng > 1) {
                int mid = (ok + ng) / 2;
                int R = r[i][mid];

                if (L < R) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            if (ok == r[i].size()) continue;
            int base = ok;

            ok = base, ng = r[i].size();
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                int R = r[i][mid];

                if (seg.query(L, R) >= i) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            ans += ok - base + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
