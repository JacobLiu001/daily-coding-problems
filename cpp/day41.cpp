#include "includes/universal.h"
using namespace std;

void dfs(const string &pos, int n, map<string, vector<pair<string, bool> > > &adj, vector<string> &ans) {
    if (ans.size() == n) {
        return ;
    }

    vector<pair<string, bool> > &nl = adj[pos];
    for (int i = 0; i < nl.size(); i++) {
        pair<string, bool> &p = nl[i];
        if (!p.second) {
            continue;
        }
        p.second = false;
        ans.push_back(p.first);
        dfs(p.first, n, adj, ans);
        if (ans.size() == n) {
            return ;
        }
        ans.pop_back();
        p.second = true;
    }
}

vector<string> day41(const vector<pair<string, string> > &v, string source) {
    vector<string> ret;
    ret.push_back(source);
    map<string, vector<pair<string, bool> > > adj;
    int n = v.size() + 1;

    for (auto &[s, t]: v) {
        adj[s].emplace_back(t, true);
    }

    dfs(source, n, adj, ret);

    if (ret.size() != n) {
        return vector<string>();
    }

    return ret;
}

int main() {
    vector<pair<string, string>> v = {
        {"SFO", "HKO"},
        {"YYZ", "SFO"},
        {"YUL", "YYZ"},
        {"HKO", "ORD"},
    };

    cout << day41(v, "YUL") << endl;
    return 0;
}
