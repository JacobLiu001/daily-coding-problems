#include "includes/universal.h"
using namespace std;

const ull NUM_TRIALS = 100000000;

double day14() {
    random_device rd;
    mt19937 rng(rd());

    ull cnt_in = 0;
    for (ull i = 0; i < NUM_TRIALS; i++) {
        double x, y;
        x = generate_canonical<double, numeric_limits<double>::digits>(rng);
        y = generate_canonical<double, numeric_limits<double>::digits>(rng);
        cnt_in += (x * x + y * y < 1);
    }

    return 4.0 * cnt_in / NUM_TRIALS;
}


int main() {
    cout << day14() << endl;
    return 0;
}
