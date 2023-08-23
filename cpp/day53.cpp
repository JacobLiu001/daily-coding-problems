#include "includes/universal.h"
using namespace std;

template<typename T>
class Queue {
private:
    stack<T> s1, s2;
public:
    void push(T &&x) {
        s1.push(x);
    }
    void push(const T &x) {
        s1.push(x);
    }

    void cleanup() {
        if (!s2.empty()) {
            return ;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    T front() {
        cleanup();
        assert(!s2.empty());
        return s2.top();
    }

    void pop() {
        cleanup();
        assert(!s2.empty());
        s2.pop();
    }

    int size() const {
        return s1.size() + s2.size();
    }

    bool empty() const {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue<int> q;
    vector<int> v({1,2,3,4,5});
    vector<int> popped;

    for (auto x: v) {
        q.push(x);
    }

    while (!q.empty()) {
        popped.push_back(q.front());
        q.pop();
    }

    assert(v == popped);
    return 0;
}
