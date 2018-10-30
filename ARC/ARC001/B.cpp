#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A, B;
int ctr = 0;
int diff;

int main()
{
    cin >> A >> B;

    diff = abs(B - A);

    ctr += diff / 10;
    diff -= ctr * 10;

    if (diff <= 2) {
        ctr += diff;
    } else if (2 < diff && diff <= 7) {
        ctr += (abs(5 - diff) + 1);
    } else {
        ctr += (10 - diff + 1);
    }

    cout << ctr << endl;

    return 0;
}
