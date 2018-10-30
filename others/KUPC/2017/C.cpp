#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

int main() {
    int A;
    string S;
    cin >> A >> S;

    int b = 0, idx = 0;
    for (int i = 0; i < S.size(); ++i) {
        b += (S[i] - 'a' + 1) * mypow(A, i - idx);

        while (b > 26) {
            // できるだけ値を引いてbをAの倍数にしたい
            // 引く値は1以上26以下

            for (int j = 26; j >= 1; --j) {
                // j引いたらbはAの倍数になるか?
                if ((b - j) % A == 0) {
                    cout << (char)('a' + j - 1);
                    b = (b - j) / A;
                    ++idx;
                    break;
                }
            }
        }
    }

    if (b > 0) cout << (char)('a' + b - 1);

    cout << endl;
    return 0;
}
