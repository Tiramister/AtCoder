#include <iostream>
#include <string>

using namespace std;

int main() {
    const string player[2] = {"First", "Second"};

    string s;
    cin >> s;

    // sの長さの偶奇がベース
    int ans = s.size() % 2;
    // sの先頭と末尾が一致するかで答えが反転する
    if (s.front() != s.back()) ans = 1 - ans;

    cout << player[ans] << endl;
    return 0;
}
