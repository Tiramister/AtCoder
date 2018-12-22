#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    ll T = 0, w = 0;
    for (ll i = 0; i < S.size(); ++i) {
        if (S[i] == 'W') {
            T += i;
            ++w;
        }
    }

    ll sum = w * (w - 1) / 2;
    // 最終状態におけるT

    cout << T - sum << endl;
    return 0;
}
