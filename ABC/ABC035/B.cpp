#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string S;
int T, dis;
int freemv = 0;
int place[2] = {0, 0};

void mymove(char s)
{
    switch (s) {
    case 'L':
        place[0]--;
        break;
    case 'R':
        place[0]++;
        break;
    case 'U':
        place[1]++;
        break;
    case 'D':
        place[1]--;
        break;
    case '?':
        freemv++;
        break;
    }
}


int main()
{
    cin >> S >> T;
    for (char s : S) {
        mymove(s);
    }

    dis = abs(place[0]) + abs(place[1]);

    switch (T) {
    case 1:
        cout << dis + freemv << endl;
        break;
    case 2:
        int rem = dis - freemv;
        if (rem > 0) {
            cout << rem << endl;
        } else {
            cout << (-rem) % 2 << endl;
        }
        break;
    }
    return 0;
}
