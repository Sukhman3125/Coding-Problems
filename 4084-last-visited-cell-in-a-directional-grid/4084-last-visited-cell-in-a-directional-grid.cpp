class Solution {
private:
    pair<int, int> dir(char c){
        if(c=='L') return {0, -1};
        if(c=='R') return {0, 1};
        if(c=='D') return {1, 0};
        return {-1 ,0};
    }
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i=0, j=0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        while(1){
            auto [di, dj] = dir(grid[i][j]);
            int _i = i+di;
            int _j = j+dj;
            if(_i < 0 || _j < 0 || _i >= m || _j >= n)
                return {i, j};
            if(vis[_i][_j])
                return {i, j};
            vis[_i][_j] = true;
            i = _i, j = _j;
        }
        return {}; // dead code
    }
};