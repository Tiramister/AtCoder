#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int c[4][4];
int a[4], b[4];
bool judge;

int main()
{
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> c[i][j];
        }
    }

    for (a[1] = 0; a[1] <= c[1][1]; a[1]++) {
        judge = true;

        for (int j = 1; j <= 3; j++) {
            b[j] = c[1][j] - a[1];
        }
        for (int i = 2; i <= 3; i++) {
            a[i] = c[i][1] - b[1];
        }

        for (int i = 2; i <= 3; i++) {
            for (int j = 2; j <= 3; j++) {
                if (c[i][j] != a[i] + b[j]) {
                    judge = false;
                }
            }
        }

        if (judge) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}
