#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string X, str = "oku";


bool judge()
{
    if (X.empty()) {
        return false;
    }

    if (X.back() == 'h') {
        X.pop_back();
        if (X.empty()) {
            X.push_back('h');
            return false;
        } else if (X.back() == 'c') {
            X.pop_back();
            return true;
        } else {
            return false;
        }
    }

    for (size_t i = 0; i < 3; i++) {
        if (X.back() == str[i]) {
            X.pop_back();
            return true;
        }
    }
    return false;
}


int main()
{
    cin >> X;

    while (judge()) {
    }
    cout << (X.empty() ? "YES" : "NO") << endl;
    return 0;
}
