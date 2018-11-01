#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    string ans;
    // 表示されている文字列

    for (char c : S) {
        if (c == 'B') {
            // ansが既に空の場合に注意
            if (!ans.empty()) ans.pop_back();
        } else {
            // 0か1の場合はそのまま末尾に挿入
            ans.push_back(c);
        }
    }

    cout << ans << endl;
    return 0;
}
