#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string pass[2];
int length_sum;

int main()
{
    cin >> pass[0] >> pass[1];
    length_sum = pass[0].size() + pass[1].size();

    for (int i = 1; i <= length_sum; i++) {
        cout << pass[i % 2 == 0][(i - 1) / 2];
    }
    cout << endl;
    return 0;
}
