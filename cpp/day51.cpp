#include "includes/universal.h"
using namespace std;

class MyRNG {
private:
    mt19937 re;
    uniform_real_distribution<double> dist;
public:
    MyRNG(): re(random_device()()), dist(0.0, 1.0) {}

    int operator()(int lo, int hi) {
        return lo + dist(re) * (hi - lo);
    }

    int operator()(int k) {
        return (*this)(0, k) + 1;
    }
};

// Fisher-Yates shuffle
template<typename RNG, typename T>
void day51(vector<T> &v) {
    RNG rng;
    for (int i = v.size() - 1; i >= 1; --i) {
        // [1, i + 1] - 1  ->  [0, i]
        int j = rng(i + 1) - 1;
        swap(v[i], v[j]);
    }
}

int main() {
    string s;
    vector<int> v({1,2,3,4,5,6,7,8,9,10});
    while (cin >> s) {
        day51<MyRNG>(v);
        cout << v << endl;
    }
    return 0;
}
