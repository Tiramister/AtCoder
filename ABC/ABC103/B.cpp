#include <iostream>
#include <string>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    T += T;
    cout << (T.find(S) != string::npos ? "Yes" : "No") << endl;
    return 0;
}
