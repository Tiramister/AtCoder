#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1 << 30;

template <class Type>
class Segtree {
public:
    explicit Segtree(int N, Type e) : length(1), e(e) {
        while (length < N) length *= 2;
        nodes.assign(length * 2, e);
    }

    Type query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return e;
        if (ql <= nl && nr <= qr) return nodes[nidx];
        Type lval = query(ql, qr, nidx * 2, nl, (nl + nr) / 2);
        Type rval = query(ql, qr, nidx * 2 + 1, (nl + nr) / 2, nr);
        return min(lval, rval);
    }

    // half-open interval [ql, qr)
    Type query(int ql, int qr) {
        return query(ql, qr, 1, 0, length);
    }

    void update(int idx, Type val) {
        int nidx = idx + length;
        nodes[nidx] = val;
        while (nidx > 0) {
            nidx /= 2;
            nodes[nidx] = min(nodes[nidx * 2], nodes[nidx * 2 + 1]);
        }
    }

    int length;
    vector<Type> nodes;
    Type e;
};

int main() {
    int N;
    cin >> N;

    vector<Segtree<int>> seg(2, Segtree<int>(N, INF));
    // seg[i] = indexを2で割った余りがiであるものだけを集めたもの
    int p[N], rev[N];
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        --p[i];
        seg[i % 2].update(i, p[i]);
        rev[p[i]] = i;
    }

    vector<int> ans;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    que.push(make_tuple(seg[0].query(0, N), 0, N));
    // (区間[l, r)で選べる最小値, l, r)

    while (!que.empty()) {
        int mi, l, r;
        tie(mi, l, r) = que.top();
        que.pop();
        ans.push_back(mi);
        int d1 = rev[mi];

        // もう一方はd1で切った後ろにおける同様の最小値
        mi = seg[(d1 + 1) % 2].query(d1 + 1, r);
        ans.push_back(mi);
        int d2 = rev[mi];

        // 分割後の半開区間
        pair<int, int> segs[3] = {{l, d1}, {d1 + 1, d2}, {d2 + 1, r}};

        for (int i = 0; i < 3; ++i) {
            tie(l, r) = segs[i];
            if (l < r) que.push(make_tuple(seg[l % 2].query(l, r), l, r));
        }
    }

    for (int a : ans) cout << a + 1 << " ";
    cout << endl;
    return 0;
}
