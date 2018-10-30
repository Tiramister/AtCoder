#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define long long ll

using namespace std;
char op[2] = {'+', '-'};
int sign[2] = {1, -1};
int comb[3];
int input;
int N[4];

int main()
{
    cin >> input;

    for (int i = 0; i < 4; i++) {
        int rank = static_cast<int>(pow(10, 3 - i));
        N[i] = input / rank;
        input -= N[i] * rank;
    }

    for (comb[0] = 0; comb[0] < 2; comb[0]++) {
        for (comb[1] = 0; comb[1] < 2; comb[1]++) {
            for (comb[2] = 0; comb[2] < 2; comb[2]++) {

                int sum = N[0];

                for (int i = 0; i < 3; i++) {
                    sum += N[i + 1] * sign[comb[i]];
                }

                if (sum == 7) {
                    cout << N[0];
                    for (int i = 0; i < 3; i++) {
                        cout << op[comb[i]] << N[i + 1];
                    }
                    cout << "=7" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
