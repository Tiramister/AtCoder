#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string s[3];

int main()
{
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    cout << 'A' << s[1][0] << 'C' << endl;
    return 0;
}
