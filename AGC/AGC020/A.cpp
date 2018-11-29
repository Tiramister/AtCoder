#include <iostream>
#include <string>

using namespace std;

int main() {
    const string player[2] = {"Alice", "Borys"};
    int N, A, B;
    cin >> N >> A >> B;
    cout << player[(B - A) % 2] << endl;
    return 0;
}
