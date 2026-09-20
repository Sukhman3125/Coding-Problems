class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto q : queries) {
            int r1 = q[0], r2 = q[2], c1 = q[1], c2 = q[3];
            for (int i = r1; i <= r2; i++) {
                ans[i][c1]++;
                if (c2 + 1 < n) ans[i][c2+1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] += ans[i][j-1];
            }
        }
        return ans;
    }
};