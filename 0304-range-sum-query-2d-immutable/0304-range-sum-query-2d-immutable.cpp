class NumMatrix {
    vector<vector<int>> pref;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        pref.assign(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                pref[i][j] =
                    matrix[i-1][j-1]
                    + pref[i-1][j]
                    + pref[i][j-1]
                    - pref[i-1][j-1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {

        return pref[r2 + 1][c2 + 1]
             - pref[r1][c2 + 1]
             - pref[r2 + 1][c1]
             + pref[r1][c1];
    }
};