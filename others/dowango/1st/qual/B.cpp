#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int main() {
    string S;
    cin >> S;
    S.push_back('$');

    int N = S.length();
    ll cnt = 0, ans = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] != '2' || S[i + 1] != '5') {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        } else {
            ++cnt;
            ++i;
        }
    }

    cout << ans << endl;
    return 0;
}
