#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A, B, C;

int main()
{
    cin >> A >> B >> C;
    cout << C / min(A, B) << endl;
    return 0;
}
