#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N, K;
vector<int> l;

int main()
{
    cin >> N >> K;
    l.resize(N);
    for (size_t i = 0; i < N; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end(), greater<int>());
    int sum = 0;
    for (size_t i = 0; i < K; i++) {
        sum += l[i];
    }

    cout << sum << endl;
    return 0;
}
