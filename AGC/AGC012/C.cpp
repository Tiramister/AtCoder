#include <deque>
#include <iostream>
#include <tuple>

using namespace std;

using ll = long long;

// (追加した文字, 構築された文字列)を返す
pair<ll, deque<ll>> rec(ll N) {
    ll n;
    deque<ll> ret;

    if (N == 1) {
        ret = {1};
        return make_pair(1, ret);
    }

    if (N % 2 == 1) {
        tie(n, ret) = rec(N / 2);
        ret.push_back(++n);
    } else {
        tie(n, ret) = rec(N - 1);
        ret.push_front(++n);
    }

    return make_pair(n, ret);
}

int main() {
    ll N;
    cin >> N;

    deque<ll> ans = rec(N).second;

    cout << ans.size() * 2 << endl;

    // 前半は作った1~lenの順列
    for (ll n : ans) {
        cout << n << " ";
    }

    // 後半は1~lenの昇順列
    for (ll i = 1; i <= ans.size(); ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
