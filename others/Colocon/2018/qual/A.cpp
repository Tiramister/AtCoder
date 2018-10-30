#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;

    cout << (A <= S.size() && S.size() <= B ? "YES" : "NO") << endl;
    return 0;
}
