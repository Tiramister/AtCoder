#include <iostream>
#include <string>

using namespace std;

const string key = "keyence";

int main() {
    string S;
    cin >> S;
    int N = S.length();

    int fore, back;
    for (fore = 0; fore < 7; ++fore) {
        if (S[fore] != key[fore]) break;
    }

    for (back = 0; back < 7; ++back) {
        if (S[N - back - 1] != key[6 - back]) break;
    }

    cout << (fore + back >= 7 ? "YES" : "NO") << endl;
    return 0;
}
