#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A, B, cnt = 0;

int main()
{
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        int n = i;
        if (n / 10000 == n % 10) {
            n -= n / 10000 * 10000;
            if (n / 1000 == n % 100 / 10) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
