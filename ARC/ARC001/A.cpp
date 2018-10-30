#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int N;
char c;
vector<int> score(4, 0);

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> c;
        score.at(c - '1')++;
    }

    sort(score.begin(), score.end());

    cout << score.at(3) << " " << score.at(0) << endl;

    return 0;
}
