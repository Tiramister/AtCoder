#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

#define ll long long

using namespace std;

string s;
int j2, j3;

int judge2()
{
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            return i + 1;
        }
    }
    return -1;
}

int judge3()
{
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 2]) {
            return i + 1;
        }
    }
    return -1;
}


int main()
{
    cin >> s;

    j2 = judge2();
    if (j2 >= 0) {
        cout << j2 << " " << j2 + 1 << endl;
        return 0;
    }

    j3 = judge3();
    if (j3 >= 0) {
        cout << j3 << " " << j3 + 2 << endl;
        return 0;
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}
