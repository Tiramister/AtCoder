#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double PI = acos(-1);

int main() {
    double e[3], R = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> e[i];
        R += e[i];
    }

    sort(e, e + 3);
    double r = max(0., e[2] - e[1] - e[0]);

    cout << fixed << setprecision(10) << PI * (R * R - r * r) << endl;
    return 0;
}
