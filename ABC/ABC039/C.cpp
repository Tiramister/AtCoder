#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const string color = "WB";
const vector<string> sound = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};

int main()
{
    string S;
    cin >> S;

    size_t ib, i;
    bool cont = false;

    for (i = 0; i < 20; i++) {
        if (S[i] != color[(i + cont) % 2]) {
            if (!cont) {
                cont = true;
                ib = i - 1;
            } else {
                break;
            }
        }
    }

    // cout << ib << " " << i << endl;

    if (i - ib == 8) {
        cout << sound[2 - ib / 2] << endl;
    } else {
        cout << sound[6 - ib / 2] << endl;
    }

    return 0;
}
