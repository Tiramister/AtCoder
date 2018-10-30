#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool next_perm(string& a) {
    int itr = a.size() - 1;
    bool judge = false;
    while (itr > 0) {
        --itr;
        if (a[itr] < a[itr + 1]) {
            judge = true;
            break;
        }
    }

    if (!judge) {
        reverse(a.begin(), a.end());
    } else {
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] > a[itr]) {
                swap(a[i], a[itr]);
                sort(a.begin() + itr, a.end());
                break;
            }
        }
    }

    return judge;
}

int main() {
    string S;
    cin >> S;
    int cnt[26];
    fill(cnt, cnt + 26, 0);

    for (char c : S) {
        ++cnt[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 0) {
            S.push_back('a' + i);
            cout << S << endl;
            return 0;
        }
    }

    string T = S;
    if (next_perm(S)) {
        for (int i = 0; i < 26; ++i) {
            cout << S[i];
            if (S[i] != T[i]) break;
        }
    } else {
        cout << -1;
    }
    cout << endl;
    return 0;
}
