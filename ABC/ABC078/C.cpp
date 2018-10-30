#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define long long ll

using namespace std;

int N, M;

int main()
{
    cin >> N >> M;
    cout << (N * 100 + M * 1800) * pow(2, M);
    return 0;
}
