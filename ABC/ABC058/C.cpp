#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int INF = 1000;

int n;
vector<string> S;
vector<int> c_num;
vector<int> c_min(26, INF);

int main()
{
    cin >> n;
    S.resize(n);
    c_num.resize(26);
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 26; j++) {
            c_num[j] = 0;
        }

        cin >> S[i];

        for (int j = 0; j < S[i].size(); j++) {
            c_num[S[i][j] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            if (c_num[j] < c_min[j]) {
                c_min[j] = c_num[j];
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (c_min[i] > 0) {
            char out = static_cast<char>(i + 'a');
            for (int j = 0; j < c_min[i]; j++) {
                cout << out;
            }
        }
    }

    cout << endl;

    return 0;
}
