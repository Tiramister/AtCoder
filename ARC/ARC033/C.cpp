#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 200010;

template <class Type>
class BIT {
public:
    // 要素数length、値valueで初期化
    explicit BIT(int length, Type value) : length(length) {
        data.assign(length + 1, value);
    }

    // [1, index]の総和を求める
    Type query(int index) const {
        Type sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= (index & -index);
        }
        return sum;
    }

    // index番目にdiffを加算
    void update(int index, Type diff) {
        while (index < length) {
            data[index] += diff;
            index += (index & -index);
        }
    }

    int length;
    std::vector<Type> data;
};

template <class Type>
std::ostream& operator<<(std::ostream& os, const BIT<Type>& bit) {
    os << "[";
    for (int i = 1; i <= bit.length; ++i) {
        os << bit.query(i) << ",";
    }
    return os << "]";
}


int main() {
    int Q;
    cin >> Q;

    BIT<int> bit(MAX_V, 0);
    for (int q = 0; q < Q; ++q) {
        int T, X;
        cin >> T >> X;
        if (T == 1) {
            bit.update(X, 1);
        } else {
            int ok = MAX_V, ng = 0;
            while (ok - ng > 1) {
                int mid = (ok + ng) / 2;
                if (bit.query(mid) >= X) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            cout << ok << endl;
            bit.update(ok, -1);
        }
        // cout << q << ":" << bit << endl;
    }
    return 0;
}
