#include "includes/universal.h"
using namespace std;

// iterative
template<typename T>
set<set<T>> powerset(set<T> s) {
    int n = s.size();
    int m = (1 << n);
    set<set<T>> ret;
    for (int i = 0; i < m; i++) {
        set<T> elem;
        int j = 0;
        for (auto x: s) {
            if (i & (1 << j)) {
                elem.insert(x);
            }
            ++j;
        }
        ret.insert(elem);
    }
    return ret;
}

// recursive
template<typename T>
set<set<T>> powerset_rec(set<T> s) {
    if (s.size() == 0) {
        return set<set<T>>();
    }
    const T x = *s.begin();
    s.erase(s.begin());
    set<set<T>> sub1 = powerset(s);
    set<set<T>> sub2;
    for (auto ss: sub1) {
        ss.insert(x);
        sub2.insert(ss);
    }
    sub1.merge(sub2);
    return sub1;
}


int main() {
    set<int> s = {1, 2, 3, 4};
    cout << powerset(s) << endl;
    cout << powerset_rec(s) << endl;
    return 0;
}
