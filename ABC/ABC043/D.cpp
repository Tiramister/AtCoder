#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();

    // 長さ2の部分文字列のチェック
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == S[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }

    // 長さ3の部分文字列のチェック
    for (int i = 0; i < N - 2; ++i) {
        if (S[i] == S[i + 2]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}
