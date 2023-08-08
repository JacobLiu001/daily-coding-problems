#include "includes/universal.h"
using namespace std;

// welp. Since no major compiler supports std::generator
// (as of this code being written, 2023-08-08)
// and I am too lazy to implement my own... so here is a class

class Day33 {
private:
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
public:
    Day33() {}

    void push(int x) {
        if (pq1.empty() || x <= pq1.top()) {
            pq1.push(x);
        } else {
            pq2.push(x);
        }
        if (!pq2.empty() && pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        } else if (!pq1.empty() && pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
    }

    double getMedian() const {
        if ((pq1.size() + pq2.size()) & 1) {
            return pq1.top();
        }
        return (pq1.top() + pq2.top()) / 2.0;
    }
};

int main() {
    int n;
    Day33 worker;
    while (cin >> n) {
        worker.push(n);
        cout << worker.getMedian() << endl;
    }
    return 0;
}
