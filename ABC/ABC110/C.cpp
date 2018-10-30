#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt[2][26];

    for (int i = 0; i < 2; ++i) {
        fill(cnt[i], cnt[i] + 26, 0);
        string S;
        cin >> S;
        for (char c : S) {
            ++cnt[i][c - 'a'];
        }
        sort(cnt[i], cnt[i] + 26);
    }

    for (int j = 0; j < 26; ++j) {
        if (cnt[0][j] != cnt[1][j]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
