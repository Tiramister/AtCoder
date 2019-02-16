#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

int main() {
    int S;
    cin >> S;

    ll ans = 0;
    int r = 0, sum = 0;
    int ldig = 0, rdig = 0, lten = 1, rten = 1;

    // l<10^8
    for (int l = 1; l < 100000000; ++l) {
        if (l == lten) ++ldig, lten *= 10;

        while (sum < S) {
            ++r;
            if (r == rten) ++rdig, rten *= 10;
            sum += rdig;
        }

        if (sum == S) ++ans;
        sum -= ldig;
    }

    // l>=10^8 区間長で総当たり
    for (int t = 1; t * 9 <= S; ++t) {
        int d = S / t;

        if (S % t == 0) {  // f(l)=f(r)=dの場合
            ans += mypow(10LL, d - 1) * 9 - t + 1 + MOD;
        } else {  // f(l)=f(r)-1=dの場合
            ++ans;
        }
    }

    cout << ans % MOD << endl;
    return 0;
}
