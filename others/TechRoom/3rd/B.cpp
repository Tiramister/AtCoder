#include <iostream>
#include <string>

using namespace std;

bool divide(string N, int K) {
    int res = 0;
    for (char c : N) {
        res = (res * 10 + c - '0') % K;
    }
    return res == 0;
}

int main() {
    string N;
    cin >> N;
    cout << (divide(N, 6) ? "yES" : "nO") << endl;
    cout << (divide(N, 11) ? "yES" : "nO") << endl;
    return 0;
}
