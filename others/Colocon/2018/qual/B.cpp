#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, X;
    string S;
    cin >> N >> X >> S;

    int t[N];
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1' && t[i] > X) {
            ans += X;
        } else {
            ans += t[i];
        }
    }

    cout << ans << endl;
    return 0;
}
