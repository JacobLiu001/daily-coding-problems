#include "includes/universal.h"
using namespace std;

template<typename T>
class MaxStack {
private:
    vector<pair<T, T> > v;
public:
    void push(const T &val) {
        if (v.size() == 0) {
            v.emplace_back(val, val);
            return ;
        }
        v.emplace_back(val, max(v.back().second, val));
    }

    T pop() {
        assert (v.size() > 0);
        T ret = v.back().first;
        v.pop_back();
        return ret;
    }

    T max() {
        assert (v.size() > 0);
        return v.back().second;
    }

    int size() const {
        return v.size();
    }

    void reserve(int capacity) {
        v.reserve(capacity);
    }
};

int main() {
    MaxStack<int> s;
    return 0;
}
