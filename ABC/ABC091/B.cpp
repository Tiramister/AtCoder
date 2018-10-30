#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, M;
struct wordnum {
    string word;
    int num;
};
vector<wordnum> X;


void sortstr(string s, int a)
{
    for (wordnum& x : X) {
        if (x.word == s) {
            x.num += a;
            // cout << x.word << " " << x.num << endl;
            return;
        }
    }
    X.push_back({s, a});
    // cout << s << " " << a << endl;
    return;
}


int main()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        sortstr(s, 1);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s;
        sortstr(s, -1);
    }

    int max = 0;
    for (wordnum x : X) {
        // cout << x.word << " " << x.num << endl;
        if (x.num > max) {
            max = x.num;
        }
    }

    cout << max << endl;
    return 0;
}
