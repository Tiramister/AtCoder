#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int a, b, n;

int main()
{
    cin >> a >> b >> n;
    while (true) {
        if (n % a == 0 && n % b == 0) {
            cout << n << endl;
            return 0;
        }
        n++;
    }
}
