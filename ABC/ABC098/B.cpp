#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 1; i < N; ++i) {
        bool used[2][26];
        fill(used[0], used[1] + 26, false);

        for (int j = 0; j < i; ++j) {
            used[0][S[j] - 'a'] = true;
        }
        for (int j = i; j < N; ++j) {
            used[1][S[j] - 'a'] = true;
        }

        int cnt = 0;
        for (int k = 0; k < 26; ++k) {
            cnt += (used[0][k] && used[1][k]);
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
