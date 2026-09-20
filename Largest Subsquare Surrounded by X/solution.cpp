class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();

        vector<vector<int>> right(n, vector<int>(n));
        vector<vector<int>> down(n, vector<int>(n));

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {

                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;
                    ans = 1;

                    if (j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if (i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                int maxSide = min(right[i][j], down[i][j]);

                for (int side = maxSide; side > ans; --side) {

                    int r = i + side - 1;
                    int c = j + side - 1;

                    if (right[r][j] < side)
                        continue;

                    if (down[i][c] < side)
                        continue;

                    ans = side;
                    break;
                }
            }
        }

        return ans;
    }
};