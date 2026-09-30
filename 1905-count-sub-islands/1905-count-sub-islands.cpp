class Solution {
    using p = pair<int, int>;
    using v = vector<vector<int>>;
    v vis;
    queue<p> q;
    int m, n;
    int cnt = 0;
    static inline vector<p> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    void bfs(v& g1, v& g2, int i, int j){
        q.push({i,j});
        vis[i][j] = true;
        bool isValid = true;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(g1[r][c] == 0) isValid = false;
            for(auto [dr, dc]: dirs){
                int _r = r+dr, _c = c+dc;
                if(_r<0 || _c<0 || _r==m || _c==n) continue;
                if(g2[_r][_c] == 0) continue;
                if(vis[_r][_c]) continue;
                vis[_r][_c] = true;
                q.push({_r, _c});
            }
        }
        if(isValid)
            cnt++;
    }
public:
    int countSubIslands(v& grid1, v& grid2) {
        m = grid1.size(), n = grid1[0].size();
        vis.assign(m, vector<int>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] == 0 || vis[i][j]) continue;
                    bfs(grid1, grid2,i, j);
            }
        }
        return cnt;
    }
};