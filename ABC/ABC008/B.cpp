#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
string S;

struct result {
    string name;
    int num;
};

vector<result> R;

void mycount(string S)
{
    for (int i = 0; i < R.size(); i++) {
        if (S == R[i].name) {
            R[i].num++;
        }
    }
    R.push_back({S, 1});
}

int max_id()
{
    int id = 0;
    for (int i = 0; i < R.size(); i++) {
        if (R[i].num > R[id].num) {
            id = i;
        }
    }
    return id;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        mycount(S);
    }
    cout << R[max_id()].name << endl;
}
