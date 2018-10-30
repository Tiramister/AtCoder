#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N;
vector<int> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (size_t i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << a.back() - a.front() << endl;

    return 0;
}
