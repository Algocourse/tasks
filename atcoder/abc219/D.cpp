#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TLunchbox {
    public:
        int x;
        int y;
};

int main() {
    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<TLunchbox> lunchboxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> lunchboxes[i].x >> lunchboxes[i].y;
    }

    vector<vector<int>> backpack(x + 1, vector<int>(y + 1, n + 1));
    backpack[0][0] = 0;

    for (const auto& lunchbox : lunchboxes) {
        for (int cur_x = x; cur_x >= 0; --cur_x) {
            for (int cur_y = y; cur_y >= 0; --cur_y) {
                if (backpack[cur_x][cur_y] < n + 1) {
                    int new_x = min(x, cur_x + lunchbox.x);
                    int new_y = min(y, cur_y + lunchbox.y);

                    backpack[new_x][new_y] = min(backpack[new_x][new_y], backpack[cur_x][cur_y] + 1);
                }
            }
        }
    }

    cout << (backpack[x][y] == n + 1 ? -1 : backpack[x][y]) << endl;

    return 0;
}
