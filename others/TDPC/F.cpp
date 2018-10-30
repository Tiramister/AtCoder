#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

class Segtree {
public:
    explicit Segtree(ll N) : V_NUM(1) {
        while (V_NUM < N) {
            V_NUM *= 2;
        }

        data.resize(V_NUM * 2);
        fill(data.begin(), data.end(), 0);
    }

    // 内部処理
    // kは節点のindex、[l, r)がその対応区間
    ll query(ll a, ll b, ll k, ll l, ll r) {
        // [a, b)と[l, r)が交わらない場合
        if (r <= a || b <= l) return 0;

        // [a, b)が[l, r)を包含する場合
        if (a <= l && r <= b) return data[k];

        // 他の場合
        // [l, r)を子に分割する
        ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return (vl + vr) % MOD;
        ;
    }

    // 外部呼び出し
    // [a, b)の最小値を求める
    ll query(ll a, ll b) {
        return query(a, b, 0, 0, V_NUM);
    }

    // 値の更新
    void update(ll i, ll v) {
        i += V_NUM - 1;
        data[i] += v;
        data[i] %= MOD;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = (data[i * 2 + 1] + data[i * 2 + 2]) % MOD;
        }
    }

    ll V_NUM;
    vector<ll> data;
};

int main() {
    ll N, K;
    cin >> N >> K;

    Segtree seg(N + 1);
    seg.update(0, 1);
    // seg[i] = 駅iまでで、駅iに停まらないパターン数

    for (ll i = 2; i < N; ++i) {
        ll s = seg.query(i - K, i);
        seg.update(i, s);
    }

    cout << seg.query(N - K + 1, N) << endl;
    return 0;
}
