#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int sx, sy, tx, ty;


void print_route(int s, int t, char c)
{
    for (int i = s; i < t; i++) {
        cout << c;
    }
    return;
}


int main()
{
    cin >> sx >> sy >> tx >> ty;
    print_route(sx, tx, 'R');
    print_route(sy, ty, 'U');
    print_route(sx, tx, 'L');
    print_route(sy, ty, 'D');

    cout << 'D';
    print_route(sx, tx + 1, 'R');
    print_route(sy - 1, ty, 'U');
    cout << "LU";
    print_route(sx - 1, tx, 'L');
    print_route(sy, ty + 1, 'D');
    cout << 'R' << endl;

    return 0;
}
