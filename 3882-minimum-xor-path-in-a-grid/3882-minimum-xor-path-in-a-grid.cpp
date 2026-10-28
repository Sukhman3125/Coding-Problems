class Solution {
private:
    unordered_set<int> seen;
    int ans = INT_MAX;
    int m, n;

    int pack(int i, int j, int curr) {
        return (i << 20) | (j << 10) | curr;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int curr) {
        curr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, curr);
            return;
        }

        if (ans == 0)
            return;

        int key = pack(i, j, curr);
        if (!seen.insert(key).second)
            return;

        if (i + 1 < m)
            dfs(grid, i + 1, j, curr);

        if (j + 1 < n)
            dfs(grid, i, j + 1, curr);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = INT_MAX;
        dfs(grid, 0, 0, 0);
        return ans;
    }
};