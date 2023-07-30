#include "includes/universal.h"
using namespace std;

int day23(const vector<vector<bool>> &m, pair<int, int> st, pair<int, int> en) {
    static const int dx[] = {0, 1, 0, -1};
    static const int dy[] = {1, 0, -1, 0};
    static const int INF = 0x7fffffff;
    queue<pair<int, int>> q;
    vector<vector<int>> dists(m.size(), vector<int>(m[0].size(), INF));
    dists[st.first][st.second] = 0;
    q.push(st);
    while (!q.empty()) {
        // auto [cx, cy] = q.front();
        const pair<int, int> &p = q.front();
        int cx = p.first, cy = p.second;
        if (p == en) {
            return dists[cx][cy];
        }
        q.pop();
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < m.size() && ny >= 0 && ny < m[0].size() && !m[nx][ny]) {
                q.emplace(nx, ny);
                dists[nx][ny] = dists[cx][cy] + 1;
            }
        }
    }
    return dists[en.first][en.second]; // returns INF if no path exists.
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<bool>> m(x, vector<bool>(y, 0));
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < y; j++) {
            m[i][j] = (s[j] == 't');
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    pair<int, int> st = make_pair(sx, sy);
    cin >> ex >> ey;
    pair<int, int> en = make_pair(ex, ey);
    cout << day23(m, st, en) << endl;
    return 0;
}
