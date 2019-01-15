#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int cnt[1000100], combo[10000100];

int main() {
    string S;
    cin >> S;

    int N = S.size();
    S += "$$";

    ll ans = 0;
    cnt[0] = 5;

    for (int i = 0; i < N; ++i) {
        if (cnt[i] >= 1 && S[i] == 'N') {
            ans += 10 + combo[i] / 10;
            cnt[i] -= 1;
            combo[i + 2] += 1;
            cnt[i + 7] += 1;
        } else if (cnt[i] >= 3 && S[i] == 'C') {
            ans += 50 + combo[i] / 10 * 5;
            for (int j = i + 1; j < i + 3; ++j) {
                S[j] = '-';
            }
            cnt[i] -= 3;
            combo[i + 4] += 1;
            cnt[i + 9] += 3;
        }

        cnt[i + 1] += cnt[i];
        combo[i + 1] += combo[i];
    }

    cout << ans << endl;
    return 0;
}
