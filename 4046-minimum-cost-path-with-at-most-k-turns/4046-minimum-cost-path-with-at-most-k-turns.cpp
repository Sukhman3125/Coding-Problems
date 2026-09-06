class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int inf = 1e9;
        vector<vector<vector<vector<int>>>> dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(5,vector<int>(k+1, inf))));
        using t = tuple<int,int,int,int,int>;
        priority_queue<t,vector<t>, greater<t>> pq;
        dist[0][0][4][0] = grid[0][0];
        pq.push({grid[0][0],0,0,4,0});
        vector<pair<int,int>> dirs= {{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            auto [cost,r,c,dir,turns] = pq.top();
            pq.pop();
            if(cost != dist[r][c][dir][turns])
                continue;
            if(r==m-1 && c==n-1)
                return cost;
            for(int i=0;i<4;i++){
                auto [dx,dy] = dirs[i];
                int nr = r+dx, nc = c+dy;
                if(nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;
                int nt = turns;
                if(dir != 4 && dir != i) nt++;
                if(nt>k) continue;
                int newCost = cost + grid[nr][nc];
                if(newCost < dist[nr][nc][i][nt]){
                    dist[nr][nc][i][nt] = newCost;
                    pq.push({newCost,nr,nc,i,nt});
                }
            }
        }
        return -1;
    }
};