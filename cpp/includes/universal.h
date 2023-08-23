// Includes bits/stdc++.h and defines some useful custom stuff
// This is not for code that goes in any deployed software

// Provided as is, with no warranty.

// This is extremely bad as it populates the std namespace
// with a lot of useless symbols but since this is just
// some quick-and-dirty algo practice, it does not matter
#include <bits/stdc++.h>

using ull = unsigned long long;

template<typename T1, typename T2>
std::ostream& operator << (std::ostream &os, const std::pair<T1, T2> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// vector output
template<typename T>
std::ostream& operator << (std::ostream &os, const std::vector<T> &v) {
    if (v.size() == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    for (size_t i = 0; i < v.size() - 1; i++) {
        os << v[i] << ", ";
    }
    os << v.back() << "]";
    return os;
}

template<typename T>
std::ostream& operator << (std::ostream &os, const std::list<T> &l) {
    if (l.size() == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    int n = l.size() - 1;
    auto it = l.begin();
    for (int i = 0; i < n; i++) {
        os << *(it++) << " <-> ";
    }
    os << *it << "]";
    return os;
}

template<typename T>
std::ostream& operator << (std::ostream &os, const std::forward_list<T> &l) {
    if (l.size() == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    int n = l.size() - 1;
    auto it = l.begin();
    for (int i = 0; i < n; i++) {
        os << *(it++) << " -> ";
    }
    os << *it << "]";
    return os;
}

// set output
template<typename T>
std::ostream& operator << (std::ostream &os, const std::set<T> &v) {
    if (v.size() == 0) {
        os << "{}";
        return os;
    }
    std::stringstream ss;
    ss << "{";
    for (auto x: v) {
        ss << x << ", ";
    }
    ss << "}";
    std::string s = ss.str();
    s.erase(s.size() - 3, 2);
    os << s;
    return os;
}