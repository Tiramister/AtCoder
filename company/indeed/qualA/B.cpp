#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string b = "indeednow";
    sort(b.begin(), b.end());

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        cout << (S == b ? "YES" : "NO") << endl;
    }
    return 0;
}
