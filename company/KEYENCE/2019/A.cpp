#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string S(4, '$');
    for (int i = 0; i < 4; ++i) {
        cin >> S[i];
    }

    for (int q = 0; q < 24; ++q) {
        if (S == "1974") {
            cout << "YES" << endl;
            return 0;
        }
        next_permutation(S.begin(), S.end());
    }

    cout << "NO" << endl;
    return 0;
}
