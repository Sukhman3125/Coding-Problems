class Solution {
    using t = tuple<int, int, int>;

    static inline pair<int, int> dirs[2] = {{0, 1}, {1, 0}};
    static inline bool vis[101][101][201];

    int inline _(char c) {
        if (c == '(')
            return 1;
        return -1;
    }

public:
    Solution() {
        for (int i = 0; i < 101 * 101 * 201; i++) {
            *(&vis[0][0][0] + i) = false;
        }
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        if (_(grid[0][0]) == -1)
            return false;
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 == 1)
            return false;
        queue<t> q;
        q.push({0, 0, _(grid[0][0])});
        while (!q.empty()) {
            auto [i, j, cnt] = q.front();
            q.pop();
            if (i == m - 1 && j == n - 1) {
                if (cnt == 0) {
                    return true;
                    continue;
                }
            }
            for (auto [di, dj] : dirs) {
                int _i = i + di, _j = j + dj;
                if (_i >= m || _j >= n)
                    continue;
                int _cnt = cnt + _(grid[_i][_j]);
                if (_cnt < 0 || vis[_i][_j][_cnt])
                    continue;
                vis[_i][_j][_cnt] = true;
                q.push({_i, _j, _cnt});
            }
        }
        return false;
    }
};