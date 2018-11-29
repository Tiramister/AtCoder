#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;

    int VV = 0;
    if (m <= 5000) {
        VV = m / 100;
    } else if (m <= 30000) {
        VV = m / 1000 + 50;
    } else if (m <= 70000) {
        VV = (m / 1000 - 30) / 5 + 80;
    } else {
        VV = 89;
    }

    cout << setw(2) << setfill('0') << VV << endl;
    return 0;
}
