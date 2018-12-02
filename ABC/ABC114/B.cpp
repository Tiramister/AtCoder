#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int ans = 1000;
    for (int i = 0; i < S.size() - 2; ++i) {
        // substrでi文字目から始まる長さ3の部分列を抽出
        // それをstoiで整数に変換
        int diff = 753 - stoi(S.substr(i, 3));

        ans = min(ans, abs(diff));
    }
    cout << ans << endl;
    return 0;
}
