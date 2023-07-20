#include "includes/universal.h"
using namespace std;

void day18(const vector<int> &v, int k) {
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while ((!dq.empty()) && v[dq.back()] <= v[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < v.size(); i++) {
        cout << v[dq.front()] << endl;
        // window is (i - k, i]
        while ((!dq.empty()) && dq.front() <= i - k) {
            dq.pop_front();
        }

        while ((!dq.empty()) && v[dq.back()] <= v[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    cout << v[dq.front()] << endl;
    return ;
}


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        day18(v, k);
    }
    return 0;
}
