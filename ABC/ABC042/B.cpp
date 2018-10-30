#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N, L;
vector<string> S;

int main()
{
    cin >> N >> L;
    S.resize(N);
    for (size_t i = 0; i < N; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    for (size_t i = 0; i < N; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}
