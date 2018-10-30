#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
vector<int> T;

int main()
{
    cin >> N;
    T.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    sort(T.begin(), T.end());
    cout << T.front() << endl;
    return 0;
}
