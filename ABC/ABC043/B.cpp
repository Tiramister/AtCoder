#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string s;
string out;

void ope(char a)
{
    if (a == '0' || a == '1') {
        out.push_back(a);
    } else if (!out.empty()) {
        out.pop_back();
    }
    return;
}


int main()
{
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        ope(s[i]);
    }

    cout << out << endl;
    return 0;
}
