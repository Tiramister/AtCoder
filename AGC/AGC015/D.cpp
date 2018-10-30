#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll A, B;
    cin >> A >> B;

    if (A == B) {
        cout << 1 << endl;
        return 0;
    }

    // A, Bで異なる一番上の桁を求める
    int h;
    for (h = 63; (A >> h) == (B >> h); --h) {};

    // それより上は全部無視できる
    A &= (1LL << h) - 1;
    B &= (1LL << h) - 1;

    // [A, 2^h - 1]は全部作れる
    ll ans = (1LL << h) - A;

    // Bの1が立っている最上位の桁を求める
    int d;
    for (d = h; d >= 0 && (B >> d) == 0; --d) {};

    // 最上位以降全部1にしたやつにしても問題ない
    // [2^h, 2^h + 2^(d+1) - 1]まで全部作れるため
    B = (1LL << (d + 1)) - 1;

    // [A, 2^h - 1]と[0, B]の交差判定
    if (A > B) {
        ans += ans + B + 1;
    } else {
        ans += (1LL << h);
    }

    cout << ans << endl;
    return 0;
}
