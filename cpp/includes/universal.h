// Includes bits/stdc++.h and defines some useful custom stuff
// This is not for code that goes in any deployed software

// Provided as is, with no warranty.

// Thise is extremely bad as it populates the std namespace
// with a lot of useless symbols but since this is just
// some quick-and-dirty algo practice, it does not matter
#include <bits/stdc++.h>

using ull = unsigned long long;

// vector output
template<typename T>
std::ostream& operator << (std::ostream &os, const std::vector<T> &v) {
    os << "[";
    for (size_t i = 0; i < v.size() - 1; i++) {
        os << v[i] << ", ";
    }
    os << v.back() << "]";
    return os;
}