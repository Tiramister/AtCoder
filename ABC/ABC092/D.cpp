#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void drawline(char c)
{
    for (int i = 0; i < 100; i++) {
        cout << c;
    }
    cout << endl;
}

void drawcheck(char c, char d, int w)
{
    for (int i = 0; i < w; i++) {
        cout << c << d;
    }
    for (int i = w; i < 50; i++) {
        cout << c << c;
    }
    cout << endl;
}


int main()
{
    int A, B;
    char mj, mn;
    cin >> A >> B;
    if (A > B) {
        mj = '.';
        mn = '*';
    } else {
        mj = '*';
        mn = '.';
        swap(A, B);  // A >= B
    }

    int diff = A - B;
    cout << (diff > 0) * (((diff - 1) / 50 + 1) * 2) + ((B - 1) / 26 + 1) * 4 << " " << 100 << endl;


    int cnt = 0;
    while (diff > 0) {
        cout << mj << mn;
        diff--;
        cnt++;
        if (cnt >= 50) {
            cout << endl;
            drawline(mn);
            cnt = 0;
        }
    }

    while (cnt % 50 > 0) {
        cout << mn << mn;
        cnt++;
        cout << endl;
    }
    drawline(mn);

    B--;

    while (B > 26) {
        drawcheck(mn, mj, 50);
        drawcheck(mj, mn, 50);
        drawline(mj);
        drawline(mn);
        B -= 26;
    }
    drawcheck(mn, mj, (B - 1) * 2);
    drawcheck(mj, mn, (B - 1) * 2);
    drawline(mj);

    return 0;
}
