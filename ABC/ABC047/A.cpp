#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<int> a(3);

int main()
{
    for (size_t i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << (a[0] + a[1] == a[2] ? "Yes" : "No") << endl;
    return 0;
}
