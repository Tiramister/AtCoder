#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int T, N, M;
vector<int> A, B;

bool judge(vector<int> Ap, vector<int> Bp)
{
    /*
    cout << "judge({";
    for (int i = 0; i < Ap.size(); i++) {
        cout << Ap[i] << " ";
    }
    cout << "\b}, {";
    for (int i = 0; i < Bp.size(); i++) {
        cout << Bp[i] << " ";
    }
    cout << "\b}) called." << endl;
    */

    if (Bp.empty()) {
        return true;
    }

    if (Ap.size() < Bp.size()) {
        return false;
    }

    int i;
    for (i = 0; i < Ap.size(); i++) {
        // cout << Ap[i] << " " << Bp.front() << endl;
        if (Bp.front() - Ap[i] >= 0) {
            if (Bp.front() - Ap[i] <= T) {
                Ap.erase(Ap.begin(), Ap.begin() + i + 1);
                Bp.erase(Bp.begin());
                return judge(Ap, Bp);
            }
        } else {
            return false;
        }
    }

    return false;
}


int main()
{
    cin >> T >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    B.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    cout << (judge(A, B) ? "yes" : "no") << endl;
    return 0;
}
