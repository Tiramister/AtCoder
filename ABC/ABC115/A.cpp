#include <iostream>

using namespace std;

int main() {
    int D;
    cin >> D;

    cout << "Christmas";

    for (int i = 0; i < D - 25; ++i) {
        cout << " Eve";
        // Eveの前にスペースが入っていることに注意
    }

    cout << endl;
    return 0;
}
