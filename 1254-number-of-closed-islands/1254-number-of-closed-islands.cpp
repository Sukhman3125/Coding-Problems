class Solution {
private:
    static inline vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    void eraseIsland(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j] = 1;
        q.push({i, j});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : dirs) {
                int _r = r + dr, _c = c + dc;
                if(_r<0 || _c<0 || _r>=m || _c>=n || grid[_r][_c] == 1)
                    continue;
                grid[_r][_c] = 1;
                q.push({_r, _c});
            }
        }
    }

    void removeBoundaryIslands(vector<vector<int>>& grid) {
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                eraseIsland(grid, i, 0);
            if (grid[i][n - 1] == 0)
                eraseIsland(grid, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0)
                eraseIsland(grid, 0, i);
            if (grid[m - 1][i] == 0)
                eraseIsland(grid, m - 1, i);
        }
    }

    int countIslands(vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1)
                    continue;
                cnt++;
                eraseIsland(grid, i, j);
            }
        }
        return cnt;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        removeBoundaryIslands(grid);

        return countIslands(grid);
    }
};