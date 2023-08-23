#include "includes/universal.h"
using namespace std;

class Rand5 {
private:
    mt19937 re;
    uniform_int_distribution<int> distrib;
public:
    Rand5():
        re(random_device()()),
        distrib(1, 5) {}

    int operator()() {
        return distrib(re);
    }
};

template<typename R5>
class Rand7 {
private:
    // best case: runs rand5engine 5 times to get 4 random numbers 1~7 (inc).
    static const int DIGITS_5 = 5;
    static const int DIGITS_7 = 4, THRESH = 7 * 7 * 7 * 7;
    R5 rand5engine;
    queue<int> q;
public:
    Rand7():
        rand5engine(),
        q() {}

    void populate() {
        int x;
        do {
            x = 0;
            for (int i = 0; i < DIGITS_5; ++i) {
                x *= 5;
                x += rand5engine() - 1;
            }
        } while (x >= THRESH);
        q.push(x % 7);
        q.push(x / 7 % 7);
        q.push(x / 7 / 7 % 7);
        q.push(x / 7 / 7 / 7);
    }

    int operator()() {
        if (q.empty()) {
            populate();
        }
        int ret = q.front();
        q.pop();
        return ret + 1;
    }
};

int main() {
    Rand5 r5;
    int cnt5[5] = {0};
    for (int i = 0; i < 5000; i++) {
        ++cnt5[r5() - 1];
    }
    for (int i = 0; i < 5; i++) {
        cout << cnt5[i] << ", ";
    }
    cout << endl;

    Rand7<Rand5> r7;
    int cnt7[7] = {0};
    for (int i = 0; i < 7000; i++) {
        ++cnt7[r7() - 1];
    }
    for (int i = 0; i < 7; i++) {
        cout << cnt7[i] << ", ";
    }
    return 0;
}
