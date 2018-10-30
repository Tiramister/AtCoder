#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int N, D, X;
    cin >> N >> D >> X;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        sum += (D - 1) / A + 1;
    }
    cout << sum + X << endl;
    return 0;
}
