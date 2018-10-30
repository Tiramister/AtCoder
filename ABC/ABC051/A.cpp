#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

char s;

int main()
{
    for (size_t i = 0; i < 19; i++) {
        cin >> s;
        if (i == 5 || i == 13) {
            cout << " ";
        } else {
            cout << s;
        }
    }
    cout << endl;
    return 0;
}
