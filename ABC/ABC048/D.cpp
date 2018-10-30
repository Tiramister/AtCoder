#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string s;
string order[2] = {"First", "Second"};

int main()
{
    cin >> s;
    cout << order[((s.front() != s.back()) + s.size()) % 2] << endl;
    return 0;
}
