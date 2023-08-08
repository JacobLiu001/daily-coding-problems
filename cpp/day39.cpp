#include "includes/universal.h"
using namespace std;

tuple<pair<int, int>, pair<int, int>, map<int, map<int, bool>>> evolve(const map<int, map<int, bool>> &board) {
    static const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    static const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    map<int, map<int, int>> cnts;

    for (auto &pxm: board) {
        for (auto &pyb: pxm.second) {
            if (!pyb.second) {
                continue;
            }
            for (int i = 0; i < 8; i++) {
                ++cnts[pxm.first + dx[i]][pyb.first + dy[i]];
            }
        }
    }

    map<int, map<int, bool>> ret;
    pair<int, int> xlims(0, 0);
    pair<int, int> ylims(0, 0);
    for (const auto &pxm: cnts) {
        for (const auto &pyb: pxm.second) {
            if (pyb.second == 3) {
                ret[pxm.first][pyb.first] = 1;
                xlims.first = min(pxm.first, xlims.first);
                xlims.second = max(pxm.first, xlims.second);
                ylims.first = min(pyb.first, ylims.first);
                ylims.second = max(pyb.first, ylims.second);
            } else if (pyb.second == 2) {
                auto it = board.find(pxm.first);
                if (it == board.end()) {
                    continue;
                }
                auto it2 = (it -> second).find(pyb.first);
                if (it2 == (it -> second).end() || (!it2 -> second)) {
                    continue;
                }
                ret[pxm.first][pyb.first] = 1;
                xlims.first = min(pxm.first, xlims.first);
                xlims.second = max(pxm.first, xlims.second);
                ylims.first = min(pyb.first, ylims.first);
                ylims.second = max(pyb.first, ylims.second);
            }
        }
    }
    return make_tuple(xlims, ylims, ret);
}

int main() {
    map<int, map<int, bool>> board;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    for (int ts = 0; ts < k; ts++) {
        cout << "Timestep " << ts << ":\n";
        auto [px, py, newboard] = evolve(board);
        board = move(newboard);
        const int height = px.second - px.first + 1;
        const int width = py.second - py.first + 1;
        int writeHeadX = px.first;
        int writeHeadY = py.first;
        cout << height << " " << width << endl;
        for (auto &[curX, row]: board) {
            for (int i = writeHeadX; i < curX; i++) {
                cout << string(width, '.') + '\n';
            }
            writeHeadX = curX;
            for (auto &[curY, b]: row) {
                if (b) {
                    if (curY > writeHeadY) {
                        cout << string(curY - writeHeadY, '.');
                    }
                    cout << '*';
                    writeHeadY = curY + 1;
                }
            }
            if (py.second >= writeHeadY) {
                cout << string(py.second - writeHeadY + 1, '.');
            }
            cout << '\n';
            writeHeadX = curX + 1;
            writeHeadY = py.first;
        }
        for (int i = writeHeadX; i < px.second; i++) {
            cout << string(width, '.') + '\n';
        }
        cout << string(width + 5, '=') << endl;
    }
    return 0;
}
