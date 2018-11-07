#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int east[N + 1];
    east[0] = 0;
    // east[i] = i文字目までのEの数

    for (int i = 1; i <= N; ++i) {
        east[i] = east[i - 1] + (S[i - 1] == 'E');
    }

    int ans = N;

    // i人目をリーダーにする
    for (int i = 1; i <= N; ++i) {
        int cnt = (i - 1 - east[i - 1]) + (east[N] - east[i]);
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
