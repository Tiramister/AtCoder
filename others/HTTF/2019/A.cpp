/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int stop_to_score(int cnt) {
    switch (cnt) {
    case 1:
        return 10;
    case 2:
        return 3;
    case 3:
        return 1;
    default:
        return 0;
    }
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void operate(int& x, int& y, int& dir, char cmd, const vector<string>& brd) {
    switch (cmd) {
    case 'S':
        if (brd[x + dx[dir]][y + dy[dir]] != '#') {
            x += dx[dir];
            y += dy[dir];
        }
        break;
    case 'L':
        dir = (dir + 3) % 4;
        break;
    case 'R':
        dir = (dir + 1) % 4;
        break;
    }
}

void operate_cmd(int& x, int& y, int& dir, char cmd, const vector<string>& brd) {
    switch (brd[x][y]) {
    case '.':
        operate(x, y, dir, cmd, brd);
        break;
    case '#':
        cerr << "In a wall" << endl;
        terminate();
    case 'D':
        for (int i = 0; i < 2; ++i) {
            operate(x, y, dir, cmd, brd);
        }
        break;
    case 'T':
        for (int i = 0; i < 3; ++i) {
            operate(x, y, dir, cmd, brd);
        }
        break;
    case 'L':
        operate(x, y, dir, (cmd == 'R' ? 'L' : cmd), brd);
        break;
    case 'R':
        operate(x, y, dir, (cmd == 'L' ? 'R' : cmd), brd);
        break;
    }
}

int calc_score(vector<string>& brd, vector<string>& cmds /*, int cmd_num */) {
    vector<vector<int>> robo_cnt(29, vector<int>(29, 0));

    for (int n = 0; n < 500; ++n) {
        int x = 14, y = 14, dir = 0;
        for (int i = 0; i < 300; ++i) {
            operate_cmd(x, y, dir, cmds[n][i], brd);
        }

        robo_cnt[x][y] += 1;
    }

    int score = 0;
    for (int x = 0; x < 29; ++x) {
        for (int y = 0; y < 29; ++y) {
            score += stop_to_score(robo_cnt[x][y]);
        }
    }

    return score;
}


int N, M, L;
const string mark = ".#TDLR";

vector<string> arrange_brd(vector<string> brd, int change_num) {
    for (int i = 0; i < change_num; ++i) {
        while (true) {
            auto new_brd = brd;
            int x = mert() % 27 + 1;
            int y = mert() % 27 + 1;
            new_brd[x][y] = mark[mert() % 6];
            if (new_brd[14][14] == '#') continue;
            brd = new_brd;
            break;
        }
    }

    return brd;
}

/*
void add_double(vector<string>& brd, int double_prob) {
    for (int x = 1; x < 28; ++x) {
        for (int y = 1; y < 28; ++y) {
            if (brd[x][y] == '#') continue;
            for (int d = 0; d < 4; ++d) {
                if (brd[x + dx[d]][y + dy[d]] == '#' && mert() % double_prob == 0) brd[x][y] = 'D';
            }
        }
    }
}
*/

vector<string> generate_brd() {
    vector<string> ret(29, string(29, '.'));

    for (int x = 0; x < 29; ++x) {
        for (int y = 0; y < 29; ++y) {
            if (x == 0 || x == 28 || y == 0 || y == 28) {
                ret[x][y] = '#';
            }
        }
    }

    return ret;
}


const int trial = 1500;

int main() {
    cin >> N >> M >> L;
    vector<string> cmds(N);

    for (int n = 0; n < N; ++n) {
        cin >> cmds[n];
    }

    vector<string> best_brd;
    int max_score = 0;

    for (int q = 0; q < 1; ++q) {
        vector<string> seg_best_brd = generate_brd();
        int seg_max_score = 0;
        for (int i = 0; i < trial; ++i) {
            vector<string> brd = arrange_brd(seg_best_brd, 1);
            int score;
            score = calc_score(brd, cmds);

            if (score > seg_max_score) {
                seg_max_score = score;
                seg_best_brd = brd;
            }
        }

        if (seg_max_score > max_score) {
            max_score = seg_max_score;
            best_brd = seg_best_brd;
        }
    }

    cout << "score: " << calc_score(best_brd, cmds) << endl;
    for (string s : best_brd) {
        cout << s << "\r\n";
    }
    cout << flush;

    return 0;
}
