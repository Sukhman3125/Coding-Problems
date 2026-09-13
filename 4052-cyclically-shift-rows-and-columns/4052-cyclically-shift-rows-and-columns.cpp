class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            int k = rowShift[i]%n;
            rotate(grid[i].begin(),grid[i].begin()+k, grid[i].end());
        }
        for(int j=0;j<n;j++){
            int k = colShift[j]%n;
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                temp[i] = grid[(i+k)%n][j];
            }
            for(int i=0;i<n;i++){
                grid[i][j] = temp[i];
            }
        }
        return grid;
    }
};