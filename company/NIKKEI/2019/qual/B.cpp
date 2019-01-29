#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string S[3];
    for (int i = 0; i < 3; ++i) cin >> S[i];

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        set<char> s;
        for (int j = 0; j < 3; ++j) s.insert(S[j][i]);
        ans += s.size() - 1;
    }

    cout << ans << endl;
    return 0;
}
