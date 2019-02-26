#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int m = stoi(S.substr(5, 2));
    cout << (m <= 4 ? "Heisei" : "TBD") << endl;
    return 0;
}
