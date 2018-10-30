#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int W, H, N;
int x, y, a;
int xl, xr, yb, yt;

void paint(int x, int y, int a)
{
    switch (a) {
    case 1:
        xl = max(x, xl);
        break;
    case 2:
        xr = min(x, xr);
        break;
    case 3:
        yb = max(y, yb);
        break;
    case 4:
        yt = min(y, yt);
        break;
    }
    return;
}


int main()
{
    cin >> W >> H >> N;
    xl = 0;
    xr = W;
    yb = 0;
    yt = H;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> a;
        paint(x, y, a);
    }

    cout << max(xr - xl, 0) * max(yt - yb, 0) << endl;
    return 0;
}
