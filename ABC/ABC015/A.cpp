#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string A, B;

int main()
{
    cin >> A >> B;
    cout << ((A.size() > B.size()) ? A : B) << endl;
    return 0;
}
