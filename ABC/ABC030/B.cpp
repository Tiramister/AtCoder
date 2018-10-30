#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

float n, m;
float n_arg, m_arg, diff;

int main()
{
    cin >> n >> m;
    m_arg = m * 6;
    if (n > 12) {
        n -= 12;
    }
    n_arg = n * 30 + m / 2;

    diff = abs(n_arg - m_arg);
    if (diff > 180) {
        diff = 360 - diff;
    }
    cout << diff << endl;
    return 0;
}
