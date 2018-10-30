#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll X[N], Y[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    // 可能性判定: X + Yのparityが全部一致していればOK
    // 負数の除算はタブーなので2^35を足している
    int parity = (X[0] + Y[0] + (1LL << 35)) % 2;
    for (int i = 1; i < N; ++i) {
        if ((X[i] + Y[i] + (1LL << 35)) % 2 != parity) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 偶数の場合は最後にLをくっつけることにして奇数に変換する
    if (parity == 0) {
        for (int i = 0; i < N; ++i) {
            ++X[i];
        }
    }

    // 実際は2^kか-2^kを選択だが,
    // 下駄として2^35-1を足すことで, 0か2^(K+1)を選択するように変更
    // さらに2で割ることで, 0か2^kを選択するように
    cout << 36 - parity << endl;
    for (int k = 0; k < 35; ++k) {
        cout << (1LL << k) << " ";
    }
    if (parity == 0) cout << 1;
    cout << endl;

    // (X, Y) -> (X - Y, X + Y)に変換
    // さらに2^35-1だけ下駄を履かせ, 2で割る
    for (int i = 0; i < N; ++i) {
        ll tmp = X[i];
        X[i] -= Y[i];
        Y[i] += tmp;

        X[i] += (1LL << 35) - 1;
        X[i] /= 2;
        Y[i] += (1LL << 35) - 1;
        Y[i] /= 2;
    }

    // 後はX, Yをそれぞれ2進変換
    // 各指示に対応する変化
    // L -> -X, -Y  R -> +X, +Y
    // U -> -X, +Y  D -> +X, -Y
    string order = "LDUR";
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 35; ++k) {
            int kind = 0;
            if ((X[i] >> k) & 1) kind += 1;
            if ((Y[i] >> k) & 1) kind += 2;
            cout << order[kind];
        }
        if (parity == 0) cout << "L";
        cout << endl;
    }
    return 0;
}
