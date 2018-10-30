#include <iostream>
using namespace std;

int main() {
    int N;
    int value;
    cin >> N >> value;
    int number[3];

    number[0] = value / 10000;
    while (number[0] > -1) {
        number[1] = (value - 10000 * number[0]) / 5000;

        while (number[1] > -1) {
            number[2] = N - number[0] - number[1];

            if (value == 10000 * number[0] + 5000 * number[1] + 1000 * number[2]) {
                cout << number[0] << " " << number[1] << " " << number[2];
                return 0;
            }
            number[1]--;
        }
        number[0]--;
    }

    cout << "-1 -1 -1";
    return 0;
}
