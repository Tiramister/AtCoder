#include <iostream>

using namespace std;

using ll = long long;


ll l[51], p[51];
// l[i] = レベルiのハンバーガーの層数
// p[i] = レベルiのハンバーガーに含まれるパティの数


// レベルNのハンバーガーの、頭からX層にパティは何枚入っているか？
ll rec(int N, ll X) {
    if (X <= 0) return 0;

    // レベルNのハンバーガーを丸々食べるケース
    // これで計算量が落ちる
    if (X >= l[N]) return p[N];

    ll ret = 0;

    // 上にあるレベルN-1のハンバーガーの分
    ret += rec(N - 1, X - 1);

    // 挟まってるパティの分
    if (X > l[N - 1] + 1) ++ret;

    // 下にあるレベルN-1のハンバーガーの分
    ret += rec(N - 1, X - l[N - 1] - 2);

    return ret;
}


int main() {
    // l, pを埋める
    l[0] = 1, p[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        l[i] = l[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    ll N, X;
    cin >> N >> X;

    cout << rec(N, X) << endl;
    return 0;
}
