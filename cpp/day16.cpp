#include "includes/universal.h"
using namespace std;

class CircularQueue {
    int N;
    string *data;
    int count;

public:
    CircularQueue(int n = 100): N(n) {
        data = new string[N];
        count = 0;
    }

    ~CircularQueue() {
        delete[] data;
    }

    void record(string order_id) {
        data[(count++) % N] = order_id;
    }

    string get_last(int i) {
        assert(i > 0 && i <= N && i <= count);
        return data[(count - i) % N];
    }
};

int main() {
    CircularQueue cq(3);
    cq.record("1");
    cq.record("2");
    cq.record("3");
    cq.record("4");
    cout << cq.get_last(1) << endl;
    cout << cq.get_last(2) << endl;
    cout << cq.get_last(3) << endl;
    return 0;
}
