#include <iostream>

using namespace std;

const string dir[17] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};

int main() {
    int Deg, Dis;
    cin >> Deg >> Dis;

    int power = 0;
    if (Dis < 15) {
        cout << "C " << 0 << endl;
        return 0;
    } else if (Dis < 93) {
        power = 1;
    } else if (Dis < 201) {
        power = 2;
    } else if (Dis < 327) {
        power = 3;
    } else if (Dis < 477) {
        power = 4;
    } else if (Dis < 645) {
        power = 5;
    } else if (Dis < 831) {
        power = 6;
    } else if (Dis < 1029) {
        power = 7;
    } else if (Dis < 1245) {
        power = 8;
    } else if (Dis < 1467) {
        power = 9;
    } else if (Dis < 1707) {
        power = 10;
    } else if (Dis < 1959) {
        power = 11;
    } else {
        power = 12;
    }

    cout << dir[(Deg * 10 + 1125) / 2250] << " " << power << endl;

    return 0;
}
