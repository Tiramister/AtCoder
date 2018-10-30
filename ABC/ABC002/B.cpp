#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string W;
size_t len;

int main()
{
    cin >> W;
    len = W.length();

    for (int i = 0; i < len; i++) {
        char c = W[i];
        if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
