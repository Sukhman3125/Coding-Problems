class Solution {
private:
    int dp[101][101][201];
    int m, n;
    bool recur(vector<vector<char>>& grid, int i=0, int j=0, int cnt=0){
        if(i>=m || j>=n) return false;
        cnt += grid[i][j] == '('?1:-1;
        if(cnt<0) return false;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        if(i == m-1 && j==n-1) return dp[i][j][cnt] = cnt==0;
        return dp[i][j][cnt] = recur(grid,i+1,j,cnt) | recur(grid,i,j+1,cnt);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        if((m+n-1)%2 == 1) return false;
        memset(dp, -1, sizeof(dp));
        return recur(grid);
    }
};